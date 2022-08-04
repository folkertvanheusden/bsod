#include <ncurses.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

unsigned int myrandom()
{
	return lrand48();
}

unsigned int random_32bit_value()
{
	return myrandom() & 0xffffffff;
}

char * random_error()
{
	static char *errors[] = {
		"ACPI_DRIVER_INTERNAL",
		"ASSIGN_DRIVE_LETTERS_FAILED",
		"ATDISK_DRIVER_INTERNAL",
		"BAD_EXHANDLE",
		"BAD_POOL_CALLER",
		"BAD_SYSTEM_CONFIG_INFO",
		"BOUND_IMAGE_UNSUPPORTED",
		"BUGCODE_USB_DRIVER",
		"CACHE_INITIALIZATION_FAILED",
		"CANCEL_STATE_IN_COMPLETED_IRP",
		"CANNOT_WRITE_CONFIGURATION",
		"CONFIG_INITIALIZATION_FAILED",
		"CONFIG_LIST_FAILED",
		"CRITICAL_SERVICE_FAILED",
		"DATA_COHERENCY_EXCEPTION",
		"DEREF_UNKNOWN_LOGON_SESSION",
		"DFS_FILE_SYSTEM",
		"DRIVER_CORRUPTED_MMPOOL",
		"DRIVER_IRQL_NOT_LESS_OR_EQUAL",
		"DRIVER_LEFT_LOCKED_PAGES_IN_PROCESS",
		"DRIVER_POWER_STATE_FAILURE",
		"DRIVER_UNLOADED_WITHOUT_CANCELLING_PENDING_OPERATIONS",
		"END_OF_NT_EVALUATION_PERIOD",
		"FATAL_UNHANDLED_HARD_ERROR",
		"FILE_INITIALIZATION_FAILED",
		"FLTMGR_FILE_SYSTEM",
		"FP_EMULATION_ERROR",
		"FTDISK_INTERNAL_ERROR",
		"HAL1_INITIALIZATION_FAILED",
		"HAL_INITIALIZATION_FAILED",
		"INSTALL_MORE_MEMORY",
		"INSTRUCTION_COHERENCY_EXCEPTION",
		"INSUFFICIENT_SYSTEM_MAP_REGS",
		"INTERNAL_POWER_ERROR",
		"INVALID_KERNEL_HANDLE",
		"INVALID_REGION_OR_SEGMENT",
		"INVALID_WORK_QUEUE_ITEM",
		"IO1_INITIALIZATION_FAILED",
		"IRQL_GT_ZERO_AT_SYSTEM_SERVICE",
		"KERNEL_DATA_INPAGE_ERROR",
		"KERNEL_MODE_EXCEPTION_NOT_HANDLED",
		"KERNEL_STACK_INPAGE_ERROR",
		"KERNEL_STACK_LOCKED_AT_EXIT",
		"LM_SERVER_INTERNAL_ERROR",
		"LPC_INITIALIZATION_FAILED",
		"MACHINE_CHECK_EXCEPTION",
		"MAILSLOT_FILE_SYSTEM",
		"MEMORY1_INITIALIZATION_FAILED",
		"MULTIPLE_IRP_COMPLETE_REQUESTS",
		"MUST_SUCCEED_POOL_EMPTY",
		"MUTEX_ALREADY_OWNED",
		"NDIS_INTERNAL_ERROR",
		"NO_BOOT_DEVICE",
		"NO_PAGES_AVAILABLE",
		"NO_SUCH_PARTITION",
		"OBJECT1_INITIALIZATION_FAILED",
		"OBJECT_INITIALIZATION_FAILED",
		"OFS_FILE_SYSTEM",
		"PAGE_FAULT_IN_NONPAGED_AREA",
		"PAGE_FAULT_WITH_INTERRUPTS_OFF",
		"PFN_LIST_CORRUPT",
		"PHASE0_EXCEPTION",
		"PINBALL_FILE_SYSTEM",
		"PNP_INTERNAL_ERROR",
		"PP0_INITIALIZATION_FAILED",
		"PP1_INITIALIZATION_FAILED",
		"PROCESS1_INITIALIZATION_FAILED",
		"PROCESS_HAS_LOCKED_PAGES",
		"PROCESS_INITIALIZATION_FAILED",
		"RECOM_DRIVER",
		"REFMON_INITIALIZATION_FAILED",
		"REF_UNKNOWN_LOGON_SESSION",
		"REGISTRY_ERROR",
		"SECURITY1_INITIALIZATION_FAILED",
		"SECURITY_INITIALIZATION_FAILED",
		"SESSION1_INITIALIZATION_FAILED",
		"SESSION2_INITIALIZATION_FAILED",
		"SESSION3_INITIALIZATION_FAILED",
		"SESSION4_INITIALIZATION_FAILED",
		"SESSION5_INITIALIZATION_FAILED",
		"SESSION_HAS_VALID_POOL_ON_EXIT",
		"SESSION_HAS_VALID_SPECIAL_POOL_ON_EXIT",
		"SESSION_HAS_VALID_VIEWS_ON_EXIT",
		"SET_ENV_VAR_FAILED",
		"SETUP_FAILURE",
		"SPECIAL_POOL_DETECTED_MEMORY_CORRUPTION",
		"SPIN_LOCK_INIT_FAILURE",
		"STREAMS_INTERNAL_ERROR",
		"SYMBOLIC_INITIALIZATION_FAILED",
		"SYSTEM_LICENSE_VIOLATION",
		"SYSTEM_THREAD_EXCEPTION_NOT_HANDLED",
		"TARGET_MDL_TOO_SMALL",
		"TERMINAL_SERVER_DRIVER_MADE_INCORRECT_MEMORY_REFERENCE",
		"UDFS_FILE_SYSTEM",
		"UNMOUNTABLE_BOOT_VOLUME",
		"UNSUPPORTED_PROCESSOR",
		"UP_DRIVER_ON_MP_SYSTEM",
		"WIN32K_INIT_OR_RIT_FAILURE",
		"WORKER_THREAD_RETURNED_AT_BAD_IRQL",
		"XNS_INTERNAL_ERROR"
	};

	return errors[myrandom() % (sizeof(errors) / sizeof(char *))];
}

char *random_sys_file(void)
{
	static char *sys_files[] = {
		"cdr4_xp.sys",
		"fs_rec.sys",
		"hsx_cnxt.sys",
		"hsx_dpv.sys",
		"ks-959.sys",
		"nv4_mini.sys",
		"sffp_sd.sys",
		"sym_hi.sys",
		"sym_u3.sys",
		"1394bus.sys",
		"ac97intc.sys",
		"acpi.sys",
		"acpiec.sys",
		"adihdaud.sys",
		"adpu160m.sys",
		"aeaudio.sys",
		"aec.sys",
		"aegisp.sys",
		"afd.sys",
		"aha154x.sys",
		"aic78u2.sys",
		"aic78xx.sys",
		"aliide.sys",
		"amdk6.sys",
		"amdk7.sys",
		"amsint.sys",
		"anc.sys",
		"ansi.sys",
		"arp1394.sys",
		"asc.sys",
		"asc3350p.sys",
		"asc3550.sys",
		"asyncmac.sys",
		"atapi.sys",
		"ati2mtag.sys",
		"atmarpc.sys",
		"atmeltpm.sys",
		"atmepvc.sys",
		"atmlane.sys",
		"atmuni.sys",
		"audstub.sys",
		"b57xp32.sys",
		"battc.sys",
		"bcbthub.sys",
		"beep.sys",
		"bluescreen.sys",
		"bridge.sys",
		"btaudio.sys",
		"btkrnl.sys",
		"btport.sys",
		"btserial.sys",
		"btslbcsp.sys",
		"btwdndis.sys",
		"btwusb.sys",
		"cbidf2k.sys",
		"ccdecode.sys",
		"cd20xrnt.sys",
		"cdaudio.sys",
		"cdfs.sys",
		"cdralw2k.sys",
		"cdrom.sys",
		"cinemst2.sys",
		"classpnp.sys",
		"cmbatt.sys",
		"cmdide.sys",
		"compbatt.sys",
		"country.sys",
		"cpqarray.sys",
		"cpqdap01.sys",
		"crusoe.sys",
		"dac2w2k.sys",
		"dac960nt.sys",
		"disk.sys",
		"diskdump.sys",
		"dmboot.sys",
		"dmio.sys",
		"dmload.sys",
		"dmusic.sys",
		"dpti2o.sys",
		"drmk.sys",
		"drmkaud.sys",
		"dxapi.sys",
		"dxg.sys",
		"dxgthk.sys",
		"e100b325.sys",
		"elbycdfl.sys",
		"elbycdio.sys",
		"enum1394.sys",
		"fastfat.sys",
		"fdc.sys",
		"fips.sys",
		"flpydisk.sys",
		"fltmgr.sys",
		"fsvga.sys",
		"ftdisk.sys",
		"hcmon.sys",
		"hdaudbus.sys",
		"hdaudio.sys",
		"hidclass.sys",
		"hidcom.sys",
		"hidparse.sys",
		"hidusb.sys",
		"himem.sys",
		"hpn.sys",
		"hsxhwazl.sys",
		"http.sys",
		"i2omgmt.sys",
		"i2omp.sys",
		"i8042prt.sys",
		"ikhfile.sys",
		"ikhlayer.sys",
		"imagedrv.sys",
		"imagesrv.sys",
		"imapi.sys",
		"ini910u.sys",
		"intelide.sys",
		"intelppm.sys",
		"ip6fw.sys",
		"ipfltdrv.sys",
		"ipinip.sys",
		"ipnat.sys",
		"ipsec.sys",
		"irda.sys",
		"irenum.sys",
		"isapnp.sys",
		"kbdclass.sys",
		"kbdhid.sys",
		"key01.sys",
		"keyboard.sys",
		"kmixer.sys",
		"ks.sys",
		"ksecdd.sys",
		"luipsec.sys",
		"mcd.sys",
		"mdmxsdk.sys",
		"mf.sys",
		"mnmdd.sys",
		"modem.sys",
		"mouclass.sys",
		"mouhid.sys",
		"mountmgr.sys",
		"mqac.sys",
		"mraid35x.sys",
		"mrxdav.sys",
		"mrxsmb.sys",
		"msfs.sys",
		"msgpc.sys",
		"mskssrv.sys",
		"mspclock.sys",
		"mspqm.sys",
		"mssmbios.sys",
		"mstee.sys",
		"mup.sys",
		"nabtsfec.sys",
		"ndis.sys",
		"ndisip.sys",
		"ndistapi.sys",
		"ndisuio.sys",
		"ndiswan.sys",
		"ndproxy.sys",
		"netbios.sys",
		"netbt.sys",
		"nic1394.sys",
		"nikedrv.sys",
		"nmnt.sys",
		"nmwcd.sys",
		"nmwcdc.sys",
		"nmwcdcj.sys",
		"nmwcdcm.sys",
		"npf.sys",
		"npfs.sys",
		"nsndis5.sys",
		"ntdos.sys",
		"ntdos404.sys",
		"ntdos411.sys",
		"ntdos412.sys",
		"ntdos804.sys",
		"ntfs.sys",
		"ntio.sys",
		"ntio404.sys",
		"ntio411.sys",
		"ntio412.sys",
		"ntio804.sys",
		"null.sys",
		"nwlnkflt.sys",
		"nwlnkfwd.sys",
		"nwlnkipx.sys",
		"nwlnknb.sys",
		"nwlnkspx.sys",
		"nwrdr.sys",
		"ohci1394.sys",
		"oprghdlr.sys",
		"p3.sys",
		"parport.sys",
		"partmgr.sys",
		"parvdm.sys",
		"pcdrndisuio.sys",
		"pci.sys",
		"pciide.sys",
		"pciidex.sys",
		"pcmcia.sys",
		"perc2.sys",
		"perc2hib.sys",
		"portcls.sys",
		"pqntdrv.sys",
		"processr.sys",
		"psadd.sys",
		"psched.sys",
		"ptilink.sys",
		"pxhelp20.sys",
		"ql1080.sys",
		"ql10wnt.sys",
		"ql12160.sys",
		"ql1240.sys",
		"ql1280.sys",
		"rasacd.sys",
		"rasirda.sys",
		"rasl2tp.sys",
		"raspppoe.sys",
		"raspptp.sys",
		"raspti.sys",
		"rawwan.sys",
		"rdbss.sys",
		"rdpcdd.sys",
		"rdpdr.sys",
		"rdpwd.sys",
		"redbook.sys",
		"rio8drv.sys",
		"riodrv.sys",
		"rmcast.sys",
		"rndismp.sys",
		"rootmdm.sys",
		"s24trans.sys",
		"scsiport.sys",
		"sdbus.sys",
		"secdrv.sys",
		"serenum.sys",
		"serial.sys",
		"sffdisk.sys",
		"sfloppy.sys",
		"sftpdrive.sys",
		"shockmgr.sys",
		"shockprf.sys",
		"slip.sys",
		"smclib.sys",
		"sonydcam.sys",
		"sparrow.sys",
		"splitter.sys",
		"sptd.sys",
		"sptddrv1.sys",
		"sr.sys",
		"srv.sys",
		"ssi.sys",
		"stream.sys",
		"streamip.sys",
		"swenum.sys",
		"swmidi.sys",
		"symc810.sys",
		"symc8xx.sys",
		"syntp.sys",
		"sysaudio.sys",
		"tape.sys",
		"tcpip.sys",
		"tcpip6.sys",
		"tcusb.sys",
		"tdi.sys",
		"tdpipe.sys",
		"tdtcp.sys",
		"termdd.sys",
		"tosdvd.sys",
		"toside.sys",
		"tphkdrv.sys",
		"tsbvcap.sys",
		"tunmp.sys",
		"udfs.sys",
		"ultra.sys",
		"update.sys",
		"usb8023.sys",
		"usbcamd.sys",
		"usbcamd2.sys",
		"usbccgp.sys",
		"usbd.sys",
		"usbehci.sys",
		"usbhub.sys",
		"usbintel.sys",
		"usbkey.sys",
		"usbport.sys",
		"usbprint.sys",
		"usbscan.sys",
		"usbuhci.sys",
		"usbvm31b.sys",
		"vdmindvd.sys",
		"vga.sys",
		"viaide.sys",
		"videoprt.sys",
		"vmnet.sys",
		"vmnetadapter.sys",
		"vmnetbridge.sys",
		"vmnetuserif.sys",
		"vmx86.sys",
		"volsnap.sys",
		"w29n50.sys",
		"w29n51.sys",
		"w39n50.sys",
		"w39n51.sys",
		"wanarp.sys",
		"watchdog.sys",
		"wbpcm.sys",
		"wbusb.sys",
		"wdmaud.sys",
		"win32k.sys",
		"wmilib.sys",
		"wpdusb.sys",
		"ws2ifsl.sys",
		"wstcodec.sys",
		"wudfpf.sys",
		"wudfrd.sys",
	};

	return sys_files[myrandom() % (sizeof(sys_files) / sizeof(char *))];
}

void bsod(WINDOW *win)
{
	int y, x;
	char *sys_file = random_sys_file();

	werase(win); 

	scrollok(win, FALSE);
	wbkgdset(win, ' ' | COLOR_PAIR(1) | A_BOLD);
	for(y=0; y<LINES; y++)
	{
		for(x=0; x<COLS; x++)
			mvwprintw(win, y, x, " ");
	}
	wmove(win, 0, 0);

	wattron(win, COLOR_PAIR(1));
	wattron(win, A_BOLD);

	wprintw(win, "\n");
	wprintw(win, "A problem has been detected and Windows has been shut down to prevent damage\n");
	wprintw(win, "to your computer.\n");
	wprintw(win, "\n");
	wprintw(win, "The problem seems to be caused by the following file: %s\n", sys_file);
	wprintw(win, "\n");
	wprintw(win, "%s\n", random_error());
	wprintw(win, "\n");
	wprintw(win, "If this is the first time you've seen this Stop error screen,\n");
	wprintw(win, "restart your computer. If this screen appears again, follow\n");
	wprintw(win, "these steps:\n");
	wprintw(win, "\n");
	wprintw(win, "Check to make sure any new hardware or software is properly installed.\n");
	wprintw(win, "If this is a new installation, ask your hardware or software manufacturer\n");
	wprintw(win, "for any Windows updates you might need.\n");
	wprintw(win, "\n");
	wprintw(win, "If problems continue, disable or remove any newly installed hardware\n");
	wprintw(win, "or software. Disable BIOS memory options such as caching or shadowing.\n");
	wprintw(win, "If you need to use Safe Mode to remove or disable components, restart\n");
	wprintw(win, "your computer, press F8 to select Advanced Startup Options, and then\n");
	wprintw(win, "select Safe Mode.\n");
	wprintw(win, "\n");
	wprintw(win, "Technical information:\n");
	wprintw(win, "\n");
	wprintw(win, "*** STOP: 0x%08x (0x%08x,0x%08x,0x%08x,0x%08x)\n", random_32bit_value(), random_32bit_value(), random_32bit_value(), random_32bit_value(), random_32bit_value());
	wprintw(win, "\n");
	wprintw(win, "\n");
	wprintw(win, "*** %12s - Address 0x%08x base at 0x%08x, DateStamp %08x\n", sys_file, random_32bit_value(), random_32bit_value(), random_32bit_value());

	wattroff(win, A_BOLD);
	wattroff(win, COLOR_PAIR(1));

	wrefresh(win);
	doupdate();
}

int main(int argc, char *argv[])
{
	srand48((int)time(NULL) + (int)getpid());

	initscr();
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLUE);

	bsod(stdscr);

	getch();
	endwin();

	fprintf(stderr, "\n\n\n\n\nbsod v" VERSION ", (C) 2007 by folkert@vanheusden.com\n\n");

	return 0;
}
