import os
import os.path
import shutil
import subprocess
import SCons.Util

if "LD_LIBRARY_PATH" in os.environ:
	os.environ["LD_LIBRARY_PATH"] = os.path.expanduser("~/lib") + ":" + os.path.expanduser("~/Qt/lib") + ":%s" % os.environ["LD_LIBRARY_PATH"]
else:
	os.environ["LD_LIBRARY_PATH"] = os.path.expanduser("~/lib") + ":" + os.path.expanduser("~/Qt/lib")

if "PKG_CONFIG_PATH" in os.environ:
	pkgconfigpath = os.environ["PKG_CONFIG_PATH"] + ":" + os.path.expanduser("~/Qt/lib/pkgconfig")
else:
	pkgconfigpath = os.path.expanduser("~/Qt/lib/pkgconfig")

env = Environment()
env['QT5DIR'] = os.path.expanduser(os.path.join("~", "Qt"))
env['ENV'] = os.environ
env['ENV']['PKG_CONFIG_PATH'] = pkgconfigpath
env.Tool('qt5')

env.EnableQt5Modules(['QtGui', 'QtCore', 'QtNetwork', 'QtWidgets'])

#env = Environment(ENV = {'PATH' : os.environ['PATH'], 'PKG_CONFIG_PATH' : pkgconfigpath}, TOOLS=["default", "qt5"], QT5DIR=os.path.expanduser("~/Qt"))

if env["PLATFORM"] != "win32":
	env.Replace(CC = "clang")
	env.Replace(CXX = "clang++")
else:
	env.Replace(TOOLS = ["mingw"])

if ARGUMENTS.get("verbose", 0):
	env.Append(CXXFLAGS = "-v")

if env["PLATFORM"] != "win32":
	env.Append(CXXFLAGS="-fPIC")

if ARGUMENTS.get("debug", 0) or "gdb" in COMMAND_LINE_TARGETS:
	env["MODE"] = "debug"
else:
	env["MODE"] = "release"

buildpath = os.path.join("build", env["MODE"], "tehrpgclient")

includedirs = []
if env["PLATFORM"] != "win32":
	includedirs = [os.path.expanduser("~/include"), os.path.expanduser("~/Qt/include")]
else:
	includedirs = []
#	includedirs = [r"\Qt\5.2.1\mingw48_32\include", r"ext\cryptopp", r"\Qt\Tools\mingw48_32\include"]

for includedir in includedirs:
	env.Append(CXXFLAGS = "-I" + includedir)

libdirs = []
if env["PLATFORM"] != "win32":
	libdirs = [os.path.expanduser("~/lib"), os.path.expanduser("~/Qt/lib")]
else:
	libdirs = []
#	libdirs = [r"\Qt\5.2.1\mingw48_32\lib", r"\Qt\5.2.1\mingw48_32\plugins\platforms", r"\Qt\Tools\mingw48_32\lib"]

env.Append(LIBPATH = libdirs)

if env["MODE"] == "debug":
	env.Append(CXXFLAGS = "-ggdb")
	env.Append(CXXFLAGS = "-O0")
	env.Append(CXXFLAGS = "-DTEHDEBUG")
elif env["MODE"] == "release":
	env.Append(CXXFLAGS = "-O3")

if env["PLATFORM"] == "win32":
	# need to build cryptopp
	#cryptoheaders = Glob("cryptopp/*.h")
	cryptosources = Glob("ext/cryptopp/*.cpp")
	cryptopp = env.Library(target=os.path.join("build", env["MODE"], "cryptopp"), source=cryptosources)
	
	libs = [cryptopp, "Qt5Core", "Qt5Gui", "Qt5Widgets", "Qt5Network", "Qt5PlatformSupport", "qwindows"]
else:
	libs = ["cryptopp"]
#	libs = ["cryptopp", "Qt5Core", "Qt5Gui", "Qt5Widgets", "Qt5Network"]
env.Append(LIBS = libs)

#env.Append(BUILDERS = {"UIC": Builder(action="uic $SOURCE -o $TARGET", prefix="../src/", suffix='_form.h', src_suffix='.ui')})
#env.Append(BUILDERS = {"MOC": Builder(action="moc $SOURCE -o $TARGET", suffix='_moc.cpp', src_suffix='.h')})

uis = Glob("src/*.ui")
uic = env.Uic5(uis)
#env.AlwaysBuild(uic)

#headers = Glob("src/*.h")
#moc = env.Moc(source=headers)
#env.AlwaysBuild(moc)

sources = Glob("src/*.cpp")

if env["PLATFORM"] == "win32":
	env.Append(LINKFLAGS="-mwindows")

client = env.Program(target=buildpath, source=sources)

#env.Depends(client, uic)

run = env.Command(source=client, target="cerr.log", action="$SOURCE 2> $TARGET")
env.AlwaysBuild(run)
env.Alias("run", run)

if env["PLATFORM"] != "win32":
	gdb = env.Command(source=client, target="gdbcerr.log", action="gdb -ex 'run 2> $TARGET' $SOURCE")
	env.AlwaysBuild(gdb)
	env.Alias("gdb", gdb)
else:
  def distzip(source, target, env):
    if SCons.Util.is_List(source):
      source = source[0]
    
    basename = os.path.basename(str(source))
    if basename[-4:] == ".exe":
      dirname = basename[:-4]
    else:
      dirname = basename
    
    if SCons.Util.is_List(target):
      target = target[0]
    
    if os.path.isdir(os.path.join("dist", dirname)):
      shutil.rmtree(os.path.join("dist", dirname))
    shutil.copytree(os.path.join("dist", "dlls"), os.path.join("dist", dirname))
    shutil.copy(str(source), os.path.join("dist", dirname, basename))
    subprocess.check_call("7z a -tzip %s %s" % (target, dirname), cwd="./dist")
    
  distzip = env.Command(source=client, target="tehrpgclient.zip", action=distzip)
  env.Alias("dist", distzip)

env.Default(client)
