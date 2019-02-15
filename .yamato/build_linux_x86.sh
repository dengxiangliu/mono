git submodule update --init --recursive
cd external/buildscripts
./bee
cd ../..
perl external/buildscripts/build_runtime_linux.pl --stevedorebuilddeps=1
mkdir -p incomingbuilds/linux32
cp -r builds/* incomingbuilds/linux32/