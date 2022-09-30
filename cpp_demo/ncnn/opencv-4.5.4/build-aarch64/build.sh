cmake -DCMAKE_INSTALL_PREFIX=../aarch64-install -DWITH_CUDA=OFF -DENABLE_PRECOMPILED_HEADERS=OFF -DCMAKE_TOOLCHAIN_FILE=../platforms/linux/aarch64-gnu.toolchain.cmake -DCUDA_GENERATION=Kepler ..
# -DCMAKE_INSTALL_PREFIX 指定编译文件make install后保存路径

make -j4
make install