#!/bin/sh

/opt/trik-dsp/cgt_c6000_7.4.2/bin/lnk6x -w -q -u _c_int00 -fs package/cfg/bin/ -q -o bin/dsp_server.xe674 package/cfg/bin/dsp_server_pe674.oe674  package/cfg/bin/dsp_server/main.oe674  package/cfg/bin/dsp_server_pe674.xdl --abi=eabi -c -m package/cfg//bin/dsp_server.xe674.map -l /opt/trik-dsp/cgt_c6000_7.4.2/lib/rts6740_elf.lib -l /opt/trik-dsp/dsplib_c674x_3_4_0_0/packages/ti/dsplib/lib/dsplib.lib
