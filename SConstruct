import os
import subprocess
import shlex

if "LD_LIBRARY_PATH" in os.environ:
	os.environ["LD_LIBRARY_PATH"] = "/home/dasterin/lib:/home/dasterin/Qt/lib:%s" % os.environ["LD_LIBRARY_PATH"]
else:
	os.environ["LD_LIBRARY_PATH"] = "/home/dasterin/lib:/home/dasterin/Qt/lib"

env = Environment(ENV = os.environ)
env.VariantDir('src', 'build', duplicate=0)

env.Replace(CC = "clang")
env.Replace(CXX = "clang++")

if ARGUMENTS.get("verbose", 0):
	env.Append(CXXFLAGS = "-v")

if ARGUMENTS.get("debug", 0) or "gdb" in COMMAND_LINE_TARGETS:
	env["MODE"] = "debug"
else:
	env["MODE"] = "release"

buildpath = os.path.join("build", env["MODE"], "tehrpgclient")

includedirs = ["/home/dasterin/include", "/home/dasterin/Qt/include"]

for includedir in includedirs:
	env.Append(CXXFLAGS = "-I" + includedir)

libdirs = ["/home/dasterin/lib", "/home/dasterin/Qt/lib"]
env.Append(LIBPATH = libdirs)

libs = ["cryptopp", "Qt5Core", "Qt5Gui", "Qt5Widgets", "Qt5Network"]
env.Append(LIBS = libs)

env.Append(CXXFLAGS="-fPIC")

if env["MODE"] == "debug":
	env.Append(CXXFLAGS = "-ggdb")
	env.Append(CXXFLAGS = "-O0")
elif env["MODE"] == "release":
	env.Append(CXXFLAGS = "-O3")

#def build_uic(target, source, env):
	#if isinstance(source, list):
		#for s in source:
			#uipath = s.path
			#hpath = os.path.join(os.path.dirname(uipath), "..", "src") + re.sub(r'''\.ui''', "", os.path.basename(uipath)) + ".h"
			#subprocess.check_call(shlex.split("uic %s -o %s" % (uipath, hpath)))

env.Append(BUILDERS = {"UIC": Builder(action="uic $SOURCE -o $TARGET", prefix="../src/", suffix='_form.h', src_suffix='.ui')})
env.Append(BUILDERS = {"MOC": Builder(action="moc $SOURCE -o $TARGET", suffix='_moc.cpp', src_suffix='.h')})

uis = Glob("ui/*.ui")
uic = env.UIC(source=uis)

headers = Glob("src/*.h")
moc = env.MOC(source=headers)

sources = Glob("src/*.cpp")
client = env.Program(target=buildpath, source=sources)
env.Default(client)

run = env.Command(source=buildpath, target="cerr.log", action="$SOURCE 2> $TARGET")
env.AlwaysBuild(run)
env.Alias("run", run)

gdb = env.Command(source=buildpath, target="gdbcerr.log", action="gdb -ex 'run 2> $TARGET' $SOURCE")
env.AlwaysBuild(gdb)
env.Alias("gdb", gdb)
