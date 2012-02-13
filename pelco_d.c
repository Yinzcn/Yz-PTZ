

#define PD_R	    0x0002 // Right
#define PD_L	    0x0004 // Left
#define PD_U	    0x0008 // Up
#define PD_D	    0x0010 // Down

#define PD_ZT	    0x0020 // Zoom Tele 
#define PD_ZW	    0x0040 // Zoom Wide 
#define PD_FF	    0x0080 // Focus Far 
#define PD_FN	    0x0100 // Focus Near
#define PD_IO	    0x0200 // Iris Open 
#define PD_IC	    0x0400 // Iris Close 
#define PD_OF	    0x0800 // Camera On / Off
#define PD_AM	    0x1000 // Auto / Manual Scan
#define PD_SN	    0x8000 // Sense

/* EXTENDED COMMANDS */
#define PD_SET_PRE	0x0003 // Set Preset
#define PD_CLR_PRE	0x0005 // Clear Preset
#define PD_GET_PRE	0x0007 // Go To Preset


HANDLE
Open_Comm_Port(void)
{
	HANDLE hFile;
	hFile = CreateFile("COM1", GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, 0, 0);
	DCB dcb;
	GetCommState(hFile, &dcb);
	dcb.BaudRate = CBR_2400;
	dcb.ByteSize = 8;
	dcb.Parity = NOPARITY;
	dcb.StopBits = ONESTOPBIT;
	SetCommState(hFile, &dcb);
	return hFile;
}


void
Close_Comm_Port(HANDLE hFile)
{
	CloseHandle(hFile);
}


int
PELCO_D_Send(HANDLE hFile,
	unsigned char addr,
	WORD cmmd,
	WORD data)
{
	unsigned char csum;
	unsigned char cmd1;
	unsigned char cmd2;
	unsigned char dat1;
	unsigned char dat2;
	unsigned char p[7];
	DWORD BytesWritten;
	cmd1 = cmmd >> 8;
	cmd2 = cmmd & 0xFF;
	dat1 = data >> 8;
	dat2 = data & 0xFF;
	csum = addr + cmd1 + cmd2 + dat1 + dat2;
	p[0] = 0xFF;
	p[1] = addr;
	p[2] = cmd1;
	p[3] = cmd2;
	p[4] = dat1;
	p[5] = dat2;
	p[6] = csum;
	printf("PELCO_D: %02X %02X %02X %02X %02X %02X %02X\n", p[0], p[1], p[2], p[3], p[4], p[5], p[6]);
	if (WriteFile(hFile, p, 7, &BytesWritten, NULL)) {
		return 1;
	} else {
		return 0;
	}
}
