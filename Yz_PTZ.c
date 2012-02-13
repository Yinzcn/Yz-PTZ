

enum YZ_PTZ_CMD {
    S, /* Stop */
    R, /* Right */
    L, /* Left */
    U, /* Up */
    D, /* Down */
    ZT, /* Zoom Tele */
    ZW, /* Zoom Wide */
    FF, /* Focus Far */
    FN, /* Focus Near */
    IO, /* Iris Open */
    IC, /* Iris Close */
    OF, /* Camera On / Off */
    AM, /* Auto / Manual Scan */
    SN  /* Sense */
}


enum YZ_PTZ_PROTOCOL {
    PELCO_D,
    PELCO_P
}


int
Yz_PTZ_cmd(YZ_PTZ_PROTOCOL prt, YZ_PTZ_CMD cmd)
{
    if (prt == PELCO_D) {
        switch (cmd) {
            case
        
        }
    }

}
