git submodule update --init --recursive
cd external/buildscripts
./bee
cd ../..
perl external/buildscripts/build_runtime_linux.pl -build64=1 --stevedorebuilddeps=1
mkdir -p incomingbuilds/linux64
cp -r builds/* incomingbuilds/linux64/