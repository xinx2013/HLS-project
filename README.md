This is a course project that modifies uBench to evaluate off-chip memory performance. For original uBench, please refer to https://github.com/SFU-HiAccel/uBench.git

### Download
```
git clone https://github.com/xinx2013/HLS-project.git
```
### Run 3 designs
```
cd HLS-project/uBench/offchip_bandwidth/datacenter/read/DDR/
```
* run baseline with 1 rank
```
cd baseline
./ubench build_dir.hw.xilinx_u200_xdma_201830_2/ubench.xclbin
```
* run proposed design with 2 sub-ranks
```
cd ../design
./ubench build_dir.hw.xilinx_u200_xdma_201830_2/ubench.xclbin
```
* run proposed design with 4 sub-ranks (optional)
```
cd ../design2
./ubench build_dir.hw.xilinx_u200_xdma_201830_2/ubench.xclbin
```
