import os
import os.path

if "LD_LIBRARY_PATH" in os.environ:
  os.environ["LD_LIBRARY_PATH"] = os.path.expanduser("~/lib") + ":" + os.path.expanduser("~/Qt/lib") + ":%s" % os.environ["LD_LIBRARY_PATH"]
else:
  os.environ["LD_LIBRARY_PATH"] = os.path.expanduser("~/lib") + ":" + os.path.expanduser("~/Qt/lib")

env = Environment(ENV = os.environ)

if env["PLATFORM"] != "win32":
  env.Append(CXXFLAGS="-fPIC")

if env["PLATFORM"] != "win32":
  env.Replace(CC = "clang")
  env.Replace(CXX = "clang++")
else:
  env.Replace(tools = ['mingw'])

if ARGUMENTS.get("verbose", 0):
	env.Append(CXXFLAGS = "-v")

if ARGUMENTS.get("debug", 0) or "gdb" in COMMAND_LINE_TARGETS:
	env["MODE"] = "debug"
else:
	env["MODE"] = "release"

buildpath = os.path.join("build", env["MODE"], "tehrpgclient")

includedirs = []
if env["PLATFORM"] != "win32":
  includedirs = [os.path.expanduser("~/include"), os.path.expanduser("~/Qt/include")]
else:
  includedirs = [r"D:\Qt\5.2.1\mingw48_32\include", r"ext\cryptopp", r"D:\Qt\Tools\mingw48_32\include"]

for includedir in includedirs:
	env.Append(CXXFLAGS = "-I" + includedir)

libdirs = []
if env["PLATFORM"] != "win32":
  libdirs = [os.path.expanduser("~/lib"), os.path.expanduser("~/Qt/lib")]
else:
  libdirs = [r"D:\Qt\5.2.1\mingw48_32\lib", r"D:\Qt\5.2.1\mingw48_32\plugins\platforms", r"D:\Qt\Tools\mingw48_32\lib"]

env.Append(LIBPATH = libdirs)

if env["MODE"] == "debug":
	env.Append(CXXFLAGS = "-ggdb")
	env.Append(CXXFLAGS = "-O0")
elif env["MODE"] == "release":
	env.Append(CXXFLAGS = "-O3")

if env["PLATFORM"] == "win32":
  # need to build cryptopp
  #cryptoheaders = Glob("cryptopp/*.h")
  cryptosources = Glob("ext/cryptopp/*.cpp")
  cryptopp = env.Library(target=os.path.join("build", env["MODE"], "cryptopp"), source=cryptosources)
  
  libs = [cryptopp, "Qt5Core", "Qt5Gui", "Qt5Widgets", "Qt5Network", "Qt5PlatformSupport", "qwindows"]
else:
  libs = ["cryptopp", "Qt5Core", "Qt5Gui", "Qt5Widgets", "Qt5Network"]
env.Append(LIBS = libs)

env.Append(BUILDERS = {"UIC": Builder(action="uic $SOURCE -o $TARGET", prefix="../src/", suffix='_form.h', src_suffix='.ui')})
env.Append(BUILDERS = {"MOC": Builder(action="moc $SOURCE -o $TARGET", suffix='_moc.cpp', src_suffix='.h')})

uis = Glob("ui/*.ui")
uic = env.UIC(source=uis)

headers = Glob("src/*.h")
moc = env.MOC(source=headers)

sources = Glob("src/*.cpp")

if env["PLATFORM"] == "win32":
  env.Append(LINKFLAGS="-mwindows")

client = env.Program(target=buildpath, source=sources)

run = env.Command(source=buildpath, target="cerr.log", action="$SOURCE 2> $TARGET")
env.AlwaysBuild(run)
env.Alias("run", run)

if env["PLATFORM"] != "win32":
  gdb = env.Command(source=buildpath, target="gdbcerr.log", action="gdb -ex 'run 2> $TARGET' $SOURCE")
  env.AlwaysBuild(gdb)
  env.Alias("gdb", gdb)

env.Default(client)