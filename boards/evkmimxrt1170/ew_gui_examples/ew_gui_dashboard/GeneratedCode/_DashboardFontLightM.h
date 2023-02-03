/*******************************************************************************
*
* E M B E D D E D   W I Z A R D   P R O J E C T
*
*                                                Copyright (c) TARA Systems GmbH
*                                    written by Paul Banach and Manfred Schweyer
*
********************************************************************************
*
* This software is delivered "as is" and shows the usage of other software 
* components. It is provided as an example software which is intended to be 
* modified and extended according to particular requirements.
* 
* TARA Systems hereby disclaims all warranties and conditions with regard to the
* software, including all implied warranties and conditions of merchantability 
* and non-infringement of any third party IPR or other rights which may result 
* from the use or the inability to use the software.
*
* This file was generated automatically by Embedded Wizard Studio.
*
* Please do not make any modifications of this file! The modifications are lost
* when the file is generated again by Embedded Wizard Studio!
*
* Version  : 10.0
* Date     : 17.02.2021  8:00:50
* Profile  : iMX_RT
* Platform : NXP.iMX_RT_VGLite.RGB565
*
*******************************************************************************/

/* Font resource used per default by 'Text' and 'Attributed Text' views to ensure 
   that new views don't remain empty on the screen. */
EW_DEFINE_FONT_RES( DashboardFontLightM, 28, 6, 0, 16, 0x0001, 0x0060 )
  EW_GLYPH( 0x0001, 0, -18, 13, 18, 12, 0x00000000 ),
  EW_GLYPH( 0x0020, 0, 0, 0, 0, 3, 0x000002A0 ),                /* ' ' */
  EW_GLYPH( 0x0021, 1, -18, 5, 18, 6, 0x000002A0 ),             /* '!' */
  EW_GLYPH( 0x0022, 0, -18, 7, 6, 7, 0x0000037A ),              /* '"' */
  EW_GLYPH( 0x0023, 0, -18, 12, 18, 12, 0x00000411 ),           /* '#' */
  EW_GLYPH( 0x0024, 0, -20, 10, 22, 10, 0x00000636 ),           /* '$' */
  EW_GLYPH( 0x0025, 0, -18, 16, 18, 16, 0x0000089F ),           /* '%' */
  EW_GLYPH( 0x0026, 0, -18, 13, 18, 12, 0x00000BDA ),           /* '&' */
  EW_GLYPH( 0x0027, 0, -18, 4, 6, 4, 0x00000E1B ),              /* ''' */
  EW_GLYPH( 0x0028, 0, -21, 7, 26, 6, 0x00000E71 ),             /* '(' */
  EW_GLYPH( 0x0029, -1, -21, 7, 26, 6, 0x00000FFA ),            /* ')' */
  EW_GLYPH( 0x002A, 0, -18, 7, 8, 7, 0x00001197 ),              /* '*' */
  EW_GLYPH( 0x002B, 0, -12, 10, 12, 11, 0x0000125A ),           /* '+' */
  EW_GLYPH( 0x002C, -1, -4, 5, 7, 4, 0x0000133E ),              /* ',' */
  EW_GLYPH( 0x002D, 0, -9, 6, 3, 6, 0x000013A5 ),               /* '-' */
  EW_GLYPH( 0x002E, 0, -4, 4, 4, 4, 0x000013DE ),               /* '.' */
  EW_GLYPH( 0x002F, -1, -18, 9, 21, 8, 0x00001413 ),            /* '/' */
  EW_GLYPH( 0x0030, 0, -18, 11, 18, 11, 0x0000159D ),           /* '0' */
  EW_GLYPH( 0x0031, 0, -18, 11, 18, 11, 0x0000175D ),           /* '1' */
  EW_GLYPH( 0x0032, 0, -18, 11, 18, 11, 0x000018BA ),           /* '2' */
  EW_GLYPH( 0x0033, 0, -18, 11, 18, 11, 0x00001AC4 ),           /* '3' */
  EW_GLYPH( 0x0034, 0, -18, 11, 18, 11, 0x00001CE3 ),           /* '4' */
  EW_GLYPH( 0x0035, 0, -18, 11, 18, 11, 0x00001E8D ),           /* '5' */
  EW_GLYPH( 0x0036, 0, -18, 11, 18, 11, 0x00002075 ),           /* '6' */
  EW_GLYPH( 0x0037, 0, -18, 11, 18, 11, 0x00002287 ),           /* '7' */
  EW_GLYPH( 0x0038, 0, -18, 11, 18, 11, 0x0000244D ),           /* '8' */
  EW_GLYPH( 0x0039, 0, -18, 11, 18, 11, 0x00002674 ),           /* '9' */
  EW_GLYPH( 0x003A, 0, -14, 4, 14, 4, 0x0000289D ),             /* ':' */
  EW_GLYPH( 0x003B, -1, -14, 5, 17, 4, 0x00002930 ),            /* ';' */
  EW_GLYPH( 0x003C, 0, -12, 10, 12, 11, 0x000029FF ),           /* '<' */
  EW_GLYPH( 0x003D, 0, -10, 10, 8, 11, 0x00002B79 ),            /* '=' */
  EW_GLYPH( 0x003E, 0, -12, 10, 12, 11, 0x00002C5A ),           /* '>' */
  EW_GLYPH( 0x003F, 0, -18, 10, 18, 9, 0x00002DD3 ),            /* '?' */
  EW_GLYPH( 0x0040, 1, -18, 17, 21, 19, 0x00002F99 ),           /* '@' */
  EW_GLYPH( 0x0041, 0, -18, 12, 18, 12, 0x0000339F ),           /* 'A' */
  EW_GLYPH( 0x0042, 1, -18, 11, 18, 13, 0x000035AF ),           /* 'B' */
  EW_GLYPH( 0x0043, 0, -18, 11, 18, 11, 0x0000377D ),           /* 'C' */
  EW_GLYPH( 0x0044, 1, -18, 12, 18, 14, 0x00003950 ),           /* 'D' */
  EW_GLYPH( 0x0045, 1, -18, 9, 18, 11, 0x00003AF6 ),            /* 'E' */
  EW_GLYPH( 0x0046, 1, -18, 9, 18, 10, 0x00003C2C ),            /* 'F' */
  EW_GLYPH( 0x0047, 0, -18, 12, 18, 13, 0x00003D52 ),           /* 'G' */
  EW_GLYPH( 0x0048, 1, -18, 12, 18, 14, 0x00003F74 ),           /* 'H' */
  EW_GLYPH( 0x0049, 1, -18, 4, 18, 6, 0x000040BF ),             /* 'I' */
  EW_GLYPH( 0x004A, 0, -18, 8, 18, 8, 0x00004126 ),             /* 'J' */
  EW_GLYPH( 0x004B, 1, -18, 12, 18, 12, 0x0000421E ),           /* 'K' */
  EW_GLYPH( 0x004C, 1, -18, 9, 18, 10, 0x000043F5 ),            /* 'L' */
  EW_GLYPH( 0x004D, 1, -18, 15, 18, 16, 0x000044DB ),           /* 'M' */
  EW_GLYPH( 0x004E, 1, -18, 12, 18, 14, 0x000046E5 ),           /* 'N' */
  EW_GLYPH( 0x004F, 0, -18, 14, 18, 14, 0x00004888 ),           /* 'O' */
  EW_GLYPH( 0x0050, 1, -18, 11, 18, 11, 0x00004AE0 ),           /* 'P' */
  EW_GLYPH( 0x0051, 0, -18, 14, 23, 14, 0x00004C4B ),           /* 'Q' */
  EW_GLYPH( 0x0052, 1, -18, 11, 18, 12, 0x00004F3E ),           /* 'R' */
  EW_GLYPH( 0x0053, 0, -18, 11, 18, 10, 0x000050CB ),           /* 'S' */
  EW_GLYPH( 0x0054, 0, -18, 11, 18, 11, 0x000052F2 ),           /* 'T' */
  EW_GLYPH( 0x0055, 1, -18, 12, 18, 14, 0x00005421 ),           /* 'U' */
  EW_GLYPH( 0x0056, 0, -18, 12, 18, 12, 0x0000559E ),           /* 'V' */
  EW_GLYPH( 0x0057, 0, -18, 18, 18, 18, 0x000057AE ),           /* 'W' */
  EW_GLYPH( 0x0058, 0, -18, 12, 18, 12, 0x00005AF0 ),           /* 'X' */
  EW_GLYPH( 0x0059, 0, -18, 12, 18, 12, 0x00005D33 ),           /* 'Y' */
  EW_GLYPH( 0x005A, 0, -18, 12, 18, 12, 0x00005EF1 ),           /* 'Z' */
  EW_GLYPH( 0x005B, 1, -20, 5, 25, 6, 0x000060E6 ),             /* '[' */
  EW_GLYPH( 0x005C, 0, -18, 7, 18, 7, 0x000061AB ),             /* '\' */
  EW_GLYPH( 0x005D, 0, -20, 5, 25, 6, 0x000062CC ),             /* ']' */
  EW_GLYPH( 0x005E, 0, -18, 9, 10, 9, 0x00006384 ),             /* '^' */
  EW_GLYPH( 0x005F, -1, 1, 12, 3, 10, 0x0000647D ),             /* '_' */
  EW_GLYPH( 0x0060, 0, -19, 6, 4, 6, 0x000064DF ),              /* '`' */
  EW_GLYPH( 0x0061, 0, -14, 11, 14, 11, 0x00006538 ),           /* 'a' */
  EW_GLYPH( 0x0062, 1, -20, 10, 20, 11, 0x000066DE ),           /* 'b' */
  EW_GLYPH( 0x0063, 0, -14, 10, 14, 10, 0x00006862 ),           /* 'c' */
  EW_GLYPH( 0x0064, 0, -20, 11, 20, 11, 0x000069DF ),           /* 'd' */
  EW_GLYPH( 0x0065, 0, -14, 11, 14, 11, 0x00006B9A ),           /* 'e' */
  EW_GLYPH( 0x0066, 0, -20, 8, 20, 7, 0x00006D48 ),             /* 'f' */
  EW_GLYPH( 0x0067, 0, -14, 11, 19, 11, 0x00006E6B ),           /* 'g' */
  EW_GLYPH( 0x0068, 1, -20, 10, 20, 12, 0x000070EE ),           /* 'h' */
  EW_GLYPH( 0x0069, 1, -18, 4, 18, 6, 0x00007239 ),             /* 'i' */
  EW_GLYPH( 0x006A, -1, -18, 6, 23, 6, 0x000072DB ),            /* 'j' */
  EW_GLYPH( 0x006B, 1, -20, 10, 20, 11, 0x000073EB ),           /* 'k' */
  EW_GLYPH( 0x006C, 1, -20, 6, 20, 6, 0x00007576 ),             /* 'l' */
  EW_GLYPH( 0x006D, 1, -14, 15, 14, 17, 0x0000762D ),           /* 'm' */
  EW_GLYPH( 0x006E, 1, -14, 10, 14, 11, 0x000077D2 ),           /* 'n' */
  EW_GLYPH( 0x006F, 0, -14, 11, 14, 11, 0x000078E4 ),           /* 'o' */
  EW_GLYPH( 0x0070, 1, -14, 10, 19, 12, 0x00007A7E ),           /* 'p' */
  EW_GLYPH( 0x0071, 0, -14, 11, 19, 11, 0x00007C12 ),           /* 'q' */
  EW_GLYPH( 0x0072, 1, -14, 7, 14, 8, 0x00007DC9 ),             /* 'r' */
  EW_GLYPH( 0x0073, 0, -14, 8, 14, 8, 0x00007E83 ),             /* 's' */
  EW_GLYPH( 0x0074, 0, -18, 7, 18, 7, 0x00007FE1 ),             /* 't' */
  EW_GLYPH( 0x0075, 1, -14, 10, 14, 11, 0x000080EB ),           /* 'u' */
  EW_GLYPH( 0x0076, 0, -14, 10, 14, 10, 0x00008208 ),           /* 'v' */
  EW_GLYPH( 0x0077, 0, -14, 15, 14, 15, 0x00008372 ),           /* 'w' */
  EW_GLYPH( 0x0078, 0, -14, 10, 14, 10, 0x000085D5 ),           /* 'x' */
  EW_GLYPH( 0x0079, 0, -14, 10, 19, 10, 0x0000876C ),           /* 'y' */
  EW_GLYPH( 0x007A, 0, -14, 10, 14, 10, 0x0000892A ),           /* 'z' */
  EW_GLYPH( 0x007B, 0, -20, 6, 25, 6, 0x00008A81 ),             /* '{' */
  EW_GLYPH( 0x007C, 1, -20, 3, 24, 5, 0x00008BCE ),             /* '|' */
  EW_GLYPH( 0x007D, 0, -20, 6, 25, 6, 0x00008C33 ),             /* '}' */
  EW_GLYPH( 0x007E, 0, -9, 10, 3, 10, 0x00008D5C ),             /* '~' */

  EW_FONT_PIXEL( DashboardFontLightM, 0x00008DDA )              /* ratio 58.01 % */
    0xBDEF7BFF, 0x6F7BDEF7, 0xEF7BDDF0, 0x3640FFBD, 0x167E26F0, 0xFD18D3D4, 0xF03E7A26,
    0x068ACD3C, 0x1B78AADE, 0xCF7FB390, 0x2F51D003, 0x58006100, 0xE200FCF1, 0xD00AB7ED,
    0x036F93CF, 0x58ACBD63, 0xF44CEE30, 0xE1A2F89B, 0x81A31A79, 0xDEEF81F7, 0x07FDEF7B,
    0x6633DCE3, 0x13010988, 0x0B090112, 0xA4040E12, 0x39D47888, 0x5977BBE1, 0xAC71601C,
    0xF77FEA73, 0x87948889, 0x69893299, 0x8C8D324D, 0xCE31FD72, 0xC2FBBF49, 0x5202822F,
    0x4A607264, 0x61DCE493, 0x3FDF1FDC, 0x00464002, 0xBBE3E748, 0x927FB8C3, 0x64384D29,
    0x93BDE484, 0x12B75873, 0x8C009180, 0xE4EEB0F7, 0xA470F2DE, 0x134D2484, 0x30052982,
    0xCC05C452, 0x4F1DC80D, 0xF27FFBC0, 0x42778BBB, 0xA90272BC, 0x6FFF2788, 0x672FEA0B,
    0xF19204C1, 0x31C82781, 0x777887E1, 0x71817CF2, 0xC83EE783, 0x141CDC46, 0x8084970C,
    0x79A4DE70, 0xB3BFE62A, 0x6AB00BB8, 0xFD4527EC, 0x7BFDF19A, 0x00880AFC, 0x06F39DF1,
    0x7BE0FDE6, 0x9F87E622, 0xAF7CA23F, 0x9131950A, 0x547487AC, 0x071E2000, 0x5390F592,
    0x5EF94416, 0xF80F9F15, 0x3DF9889E, 0xEF881319, 0x0A8E379C, 0x6B796400, 0xCF805DDF,
    0x4BE30DF0, 0x817EFA60, 0xB113C078, 0x01D37186, 0x531E0AC7, 0x900F9642, 0xF0C319F0,
    0x1F4C0E98, 0xE33718BF, 0x8C9C88C1, 0xB25F186F, 0x00BFF7FE, 0x01FCA76F, 0x8580A139,
    0x208C6DBE, 0xFF7B3C51, 0x504FE049, 0xE8804BC1, 0xC93BDCF0, 0xF5110003, 0x1FC44006,
    0x3C8B7BBF, 0x0200AA1E, 0x26000200, 0x2E09AA4F, 0x24BFBFF1, 0x40033C4F, 0x514CFF94,
    0x7A8D37BF, 0x223279CE, 0x24CC9C93, 0xFFE13322, 0x4C42E742, 0xF87C3313, 0x46D23254,
    0x3033F851, 0x8216180D, 0x000200C4, 0x20803004, 0x0D305861, 0x145033F8, 0xA9F0DA46,
    0x621F0CC4, 0xF8B9D09A, 0x1633C436, 0x2BC2F1E2, 0x41F0C626, 0xE14D8119, 0x03088FE1,
    0x012584D2, 0x09000481, 0xA424B020, 0x87890889, 0x31E14D8D, 0xBC3E9182, 0x178F1262,
    0xF2058CF1, 0xF5044424, 0x72B79E3E, 0xE639DEBE, 0x45FF187F, 0xAE7E0E46, 0xC13A3B26,
    0x052036FF, 0xCF200000, 0x777BCCBD, 0x00446004, 0x997B9E46, 0x00006EF7, 0x81D20000,
    0xA64FDFF8, 0xCA4862C7, 0x525653E5, 0xEF7BDD6D, 0xE40F207B, 0x30CEEE73, 0xF600C320,
    0x043181FD, 0x51F83628, 0x14264310, 0x506CB80F, 0x028460A2, 0x163F06C5, 0x8A0230C4,
    0x581F9B02, 0x0508C062, 0x05360B8A, 0xD8A02A51, 0x005DFAA0, 0x13FF7FEB, 0x6DF29DBC,
    0x392B04D4, 0x28FC1DD4, 0x41928AFE, 0x2C4C643A, 0x00001903, 0xC0000130, 0x9626000C,
    0x1D20CC81, 0x457F1432, 0xF83BA871, 0xC4AC1351, 0x86DF29DB, 0x1E77FA7C, 0x56FFF38C,
    0x80056245, 0x100B3C67, 0x00006BFB, 0x00000000, 0x00000000, 0x00000000, 0xF45EE790,
    0x8801113D, 0xCA44008C, 0x3BFEE7DE, 0xC846BDC8, 0x900543B5, 0xDF6B2B3F, 0xFFC4A0FF,
    0x088FE437, 0x878022E0, 0x03E4AC01, 0x782632F9, 0x31660B83, 0x2F934407, 0x782F05F8,
    0x68829E1E, 0x24DE07E2, 0x24F7BDCE, 0x100D8880, 0x7BFFBC61, 0x67FC44F7, 0x0097DE32,
    0xCFAFC1CC, 0x0ACF146D, 0x8040800B, 0xEB0B11F8, 0x03FE479E, 0x181C0207, 0xEF7581FF,
    0xD40BC42F, 0x088700A2, 0xBFF222E0, 0x97D24D42, 0xF82FEE7D, 0x732D401C, 0xFF4611CF,
    0x67BDEF00, 0x04C49C80, 0x00B9003F, 0xD310017C, 0x5F0DE008, 0xB0165300, 0x578037C2,
    0x1986604C, 0x07BAC7C0, 0xE400BBDF, 0x7BCE401F, 0x5EF83DEF, 0x44000000, 0x7B9D498A,
    0x3177BDEF, 0x1C003802, 0xBDEF750E, 0x8202418B, 0xBD9D6000, 0x6F462260, 0xBF34604C,
    0x782FEF7B, 0x00645A80, 0x5C000017, 0x5AA75F84, 0xFFAD4F0C, 0x802F05FD, 0x4ABE78F5,
    0x9806BF51, 0xFE301FFF, 0xF8C2566F, 0x1FE20327, 0x2F89DBE2, 0x2A81FFC4, 0x4E43807A,
    0x777D88A0, 0xC618C191, 0x57804CAF, 0x0E4DBDE0, 0x01E0AC78, 0x3162620C, 0x2B5C11C8,
    0x36EA5E58, 0x7C815695, 0x6B94EBF1, 0xDEF73CA7, 0x223DEF7B, 0x00223100, 0xEF7B9E56,
    0x8B01449D, 0x1FC13C05, 0x78816438, 0xFC158078, 0x80633F80, 0x83C07E2C, 0x00A8FC09,
    0x1F807063, 0x0543C051, 0x8300E4A8, 0xFFE88051, 0xF6225F3D, 0xA4ECF14A, 0x62CBC413,
    0xF82297DD, 0x63C10899, 0x6CF43C20, 0x5BC4378A, 0x782725E2, 0x7E816793, 0xF8379E68,
    0xFE6FC919, 0x0F089A88, 0x58980022, 0xFA0E6616, 0x01386336, 0xA67B92E2, 0xBC40F678,
    0x8C17BBFF, 0x1FE8D33B, 0xC69A806E, 0xE7E0EFA0, 0xCC8F9621, 0x0020F060, 0x1E5C8398,
    0x5F7D0544, 0xF4803F2C, 0x1925437C, 0x06FEFB3C, 0x03E0AC05, 0x3019E5E3, 0x187F21FF,
    0x02710DFB, 0x180F6306, 0xE13BBC63, 0x18677739, 0xE73C6190, 0x7800006E, 0x0619DDCE,
    0x739E1864, 0xC8030CB7, 0x6EE73C30, 0xE2000000, 0x1E993F7F, 0x9729218B, 0x3549594F,
    0xCC07F440, 0xBF6A02BB, 0x6FDF9061, 0x7EF5B788, 0xACF4EE78, 0x082FBF90, 0xE30EA804,
    0x9DD605F7, 0xF10BB9E1, 0x0BF44BFE, 0x07A5F7E3, 0xF33DFE78, 0xBDEF7BDE, 0x08C00777,
    0xDEF79180, 0x1BBDEF7B, 0xDEF7BC80, 0x01DDEF7B, 0x8C600230, 0xEC6B003D, 0xCF0CC12F,
    0x44BB905E, 0xEFE41FFF, 0x06FDF90B, 0x06A93B9E, 0x9E4EF300, 0x61BDF8D7, 0xFF1CBEFC,
    0x662EEF12, 0xA213BAC4, 0xFCF00776, 0xC9BFFDCE, 0xDCE42AFA, 0x73688025, 0x460CF7BD,
    0x030A29E8, 0x83D09114, 0x0FE45A82, 0x9E06F25E, 0xCFE12714, 0x03F8201A, 0x6017FEEF,
    0x33DF6024, 0x002E2181, 0x801710C0, 0xF9EE77E7, 0x7BF7200A, 0xFDFBBDEE, 0x3F6BB180,
    0x1F5DE621, 0x90367FE4, 0x4FBC29E7, 0xCF2FCEFB, 0xAA9751C9, 0x3B513DF6, 0x5B87EC22,
    0xD2083C63, 0xF7F51188, 0x2C24DE63, 0x00F8A51E, 0x5219290C, 0x204938B2, 0x80018608,
    0x90201EC5, 0xF03E7C84, 0x8F425EF0, 0x667F26E9, 0x8F0EB750, 0xF718CE61, 0x60FFA8CD,
    0xECF78FE4, 0x1BF3FF9C, 0x00019BF0, 0x0000FCCC, 0xEA2BF5FF, 0x77B10017, 0x0023D3DF,
    0x7FDEFFC4, 0x01649502, 0x08F0361B, 0x90E43016, 0x149CC501, 0xFE7FFE0C, 0x018319B0,
    0x83C3CF0F, 0x6291190C, 0xC5162C50, 0xE1F7B9E5, 0x912C014F, 0xCE0F9900, 0x936B07BD,
    0xC1FF2441, 0x362D4982, 0xEF7589FC, 0x26FCF7BD, 0x2FBD4407, 0xEF207300, 0x03C050FD,
    0x89302400, 0x2BEF7907, 0x03CF003E, 0xEF2076A0, 0x817C87FD, 0x18300A2C, 0xA3004180,
    0xEEF79078, 0xCF9800E0, 0x0BDF5101, 0xFFDCEFE6, 0x856FD887, 0x00DF827C, 0xEE43C619,
    0xF43F2E7B, 0x0F114910, 0xC1102490, 0x00000002, 0x60160400, 0x1E0F0030, 0x895F8FE0,
    0xDDF88AA2, 0x09BC1BF3, 0x23DFF24C, 0xDEEB53E4, 0x4DF9EF7B, 0x7EF5101C, 0x38167800,
    0x601F0777, 0x0A0164BC, 0x80389003, 0x00000240, 0x90200000, 0x1401C480, 0xB25E3006,
    0x7C1DDCE0, 0x01CB3C00, 0xBAC7EF51, 0xEF7BDEF7, 0x3001803E, 0x377BDCE0, 0xE0000000,
    0x801F7BDC, 0xF7384804, 0x000007DE, 0xDCE00000, 0x38C0377B, 0xBDEEB180, 0x1CFBDEF7,
    0x9C240240, 0x0003EF7B, 0xF7380000, 0x0044049E, 0x7BDCE022, 0x00000012, 0xB8000000,
    0xFCC00461, 0x137E7B9D, 0x510ADFB1, 0x006FCBEF, 0xBF10F1AE, 0x7E9EBF7B, 0xA2CF15F8,
    0x24900788, 0xDE658220, 0x0206EF7B, 0x98001006, 0x05822277, 0x11402490, 0x1DE1F805,
    0x7DC878C0, 0xC00DF827, 0x42B7EC43, 0xCEB7DF3E, 0xEF77C3FD, 0x16064277, 0x0000000B,
    0x00000000, 0x137BDCE0, 0x70000000, 0x0009BDEE, 0x00000000, 0x80000000, 0xAC503213,
    0x2837F7BE, 0x00000000, 0x18000000, 0xFF739E14, 0x00990C81, 0x00000000, 0x00000000,
    0x08B80000, 0xDEE7C83C, 0xF6881CA4, 0x43FEA21F, 0xDEF1BBDF, 0x8830627B, 0x0CC013C5,
    0x1463E02E, 0x380BC950, 0xF14403E4, 0x1390CC03, 0xE001F1F0, 0x04AC7C00, 0x403F10CC,
    0x87002B14, 0xCC950178, 0x04C47C00, 0x1835E0CC, 0x9E6A22C4, 0x230DC1BB, 0x00000000,
    0x00000000, 0x00000000, 0xC0000000, 0x400CF7B9, 0xECC403CC, 0xE7181B7B, 0x82560DFE,
    0x07E0321B, 0xA2560035, 0x1A8FC401, 0x00D4AC00, 0x0018DF88, 0x01E6AC2A, 0xF8CA29AC,
    0xBC0DE203, 0x1E326200, 0x02F0DE00, 0x007EEE20, 0x00000620, 0x00000000, 0x21180A0C,
    0xE079EFA3, 0xE21DF739, 0xF1850C85, 0xC005E000, 0x01F80098, 0xF1402720, 0x17291803,
    0xE00F9A20, 0xBC037219, 0x10CF003C, 0x55001A00, 0x8C006800, 0xDE1710C2, 0xB9F6B050,
    0xEEC403BB, 0x03BAC611, 0x8388037E, 0x2EE750F1, 0x8743F172, 0x620C7E4E, 0x3C3C18A0,
    0x20043070, 0x206002B0, 0x18008000, 0x2C080108, 0x0C1C0F0F, 0x06281883, 0xE4E8743F,
    0x73A878C7, 0x1BF0B917, 0xDD881C40, 0x07758C23, 0xEF7BDEEB, 0x720D83BF, 0x0D9004ED,
    0x101419EE, 0x0000223F, 0x323F1000, 0x03C19EE0, 0xFD901AA0, 0x2FFDEE03, 0x00000000,
    0x36000000, 0xCFB98005, 0xEFC01DDD, 0x3DAC611D, 0x0F202DE0, 0x2EE75272, 0x43A0F272,
    0x31367F27, 0x07931450, 0x0404860E, 0x040C0056, 0x03001000, 0xC1A60400, 0x21E90703,
    0x8D864512, 0x93C52566, 0x7E34E73C, 0x4E811178, 0x2E6017D4, 0x5815DCF0, 0x3DE8806F,
    0x90277989, 0x0FE22EEF, 0xB86F7E30, 0x55FBCC00, 0xFDEF7BDF, 0xAE403077, 0xC1A2009B,
    0xFC0283BD, 0x7E000008, 0x7077B814, 0x002BE201, 0xB80FC400, 0x3300F12F, 0x028780D8,
    0x8181326C, 0x507B0A02, 0x7BEF4098, 0xD7B1137E, 0x3D16F510, 0x9C62C580, 0x8221EBFB,
    0x6C05A85F, 0x817A8220, 0xC0FFF307, 0x91AFC81B, 0x60F580FF, 0xC40E07DC, 0xE780A1F7,
    0xF0890041, 0x187C95FF, 0xFF77EB2A, 0xF00667C9, 0x10E7B94C, 0xF77C7EF5, 0xBDEF7BDE,
    0x67004D77, 0xBDDF3802, 0x02EF7D8D, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x06432000, 0xEC1FDEFA, 0xC260D77B, 0x000000E0, 0x00000000, 0x00000000, 0x00000000,
    0x48904000, 0x78AF1FC4, 0x79827FF1, 0x7E4F914F, 0xF6A1C401, 0xC3BAC64C, 0xF305DEEF,
    0x83F05FDC, 0xE127F07F, 0x64911461, 0x131607B0, 0xC832418F, 0x4FE7F0F0, 0x2E2C59B1,
    0xC879248B, 0xA0620C60, 0xF81E1E78, 0x06032E73, 0xAC50D923, 0x4C8603C9, 0x2C11E019,
    0x2A06C2E0, 0x4F77C288, 0xC5F7BDE3, 0x510DF73A, 0x30EC2878, 0x31248906, 0x190887D9,
    0x907C9248, 0x67894C26, 0x520A4B04, 0xC7492190, 0xF164C708, 0x0C39A470, 0x5A4B9FC9,
    0x830E9A62, 0x43FE9087, 0x33061E4A, 0x229C8719, 0x3CF17290, 0xE2C0F4CC, 0x19B0622F,
    0xA43CA7F0, 0x34830FE2, 0x0F059258, 0x885FCFE1, 0x062C4884, 0x64C8A01E, 0xDCE31B06,
    0xBDFF8933, 0x54FE20EF, 0x361E2D72, 0x59447D31, 0x8F60C64C, 0xFD47C3E0, 0xE30CC4A8,
    0xCA4582E1, 0x407C1F02, 0xA0F81FC1, 0x25149E02, 0x9FD61C26, 0x17F8A30F, 0xE5447C59,
    0xE2C588E0, 0xFE0AC547, 0x5936B114, 0xF7DEC18C, 0x9EE751FE, 0xFF0721E7, 0x8FC3F310,
    0x9418C6A2, 0x18F9FC91, 0x0664C459, 0xF93099B5, 0x28FC1F17, 0x1C14612A, 0x80788FE0,
    0x00000585, 0x00000000, 0x88000000, 0xEEFC1714, 0x7BDEF7BD, 0x0C601337, 0x7BBF0013,
    0x01A89DEF, 0x6F02E162, 0xC4C40A30, 0x3C60CC0B, 0x98178BC0, 0x0FC03E41, 0x3126603F,
    0xF02F0F81, 0x2F01620C, 0xEB035026, 0x08EF7BDE, 0x0013E600, 0xC9EF77E6, 0xC8220445,
    0x00000093, 0x00000000, 0x00000000, 0xB1112790, 0x83F73888, 0xC288F054, 0xC8D8A065,
    0x818940F0, 0x8FE1E14D, 0x911E0A11, 0x170614D8, 0x8990C145, 0x46CFE162, 0x7BDCF1A5,
    0x3C26E267, 0x00000007, 0x00000000, 0x00000000, 0x8909073C, 0x7C015A8B, 0x0509E0DD,
    0x79603936, 0x8E3150FC, 0x91557F07, 0x8F1ED949, 0xF3F6CA91, 0x63227878, 0xBDEF7BDC,
    0x273BDEF7, 0x88013100, 0xDE23E738, 0x79561E78, 0xCC18D5F1, 0x37FFB9DF, 0x390ADEB1,
    0x34409077, 0x19EEFACF, 0x3F11FA14, 0x0D3ED612, 0xA008F762, 0x3CC58007, 0x02FC110D,
    0x4887F4C0, 0x1F01F77E, 0x115AD224, 0xC678CECF, 0x8A02EF7B, 0x0000000D, 0xFD600000,
    0x51827FEE, 0x34007DF2, 0xC0E4DB8C, 0xC080F132, 0x00001001, 0x98B81008, 0xE79030B1,
    0x5A030A25, 0x3D11D389, 0x7E7BEE61, 0x8877BE0F, 0xC03D4AFA, 0x7F7D8972, 0xA1A8786B,
    0x007F045A, 0x81800609, 0xE01C1104, 0x72F50D61, 0x737F7D88, 0xF1601E78, 0x2BF510F5,
    0x9FF7FE20, 0x000CA640, 0x00000000, 0xFFE77F20, 0x2722B701, 0x93600958, 0x4F0F03E7,
    0x02E0884C, 0x60000090, 0xC01C1100, 0xF961F943, 0x9842EE33, 0x96E48189, 0x6063153A,
    0x80DE7BED, 0xFF310F5F, 0xE4C60598, 0x9FCDB8CF, 0x47879F87, 0x80892904, 0x00185EEF,
    0x1115800C, 0x36F7BDF4, 0x1D1A5F0F, 0xF77FF25C, 0x0F026A6A, 0x58C2B7DE, 0x9CEFE47F,
    0x6622B717, 0xC4A644AA, 0x004813FE, 0x01A671AA, 0x6A8E018E, 0x0000099C, 0x00000000,
    0x08C00000, 0x73DE2023, 0xC5B7BDEF, 0x3786019E, 0xEEF8A901, 0xE3C15FA2, 0xF1E09FC7,
    0x1777C503, 0x3904DE7F, 0xDCF10F89, 0x9EE35F20, 0x0C43312F, 0xCFB909E0, 0xA216226F,
    0xCD358FDE, 0x95E19E2E, 0x664DFAEF, 0x43C43184, 0xCF7D8844, 0xE8058F10, 0xF215BEF0,
    0xDBDF53D9, 0x000060C0, 0x00000000, 0x2FF3BF90, 0xBF22B758, 0x214448C0, 0x79E246BE,
    0x00000026, 0x00000000, 0x0C000000, 0xE6314886, 0xEC46EB39, 0x39E7B11B, 0xC1EDEFAB,
    0x00000000, 0x60C18000, 0x11B8B39E, 0x99B11B9B, 0xDEFA2CE7, 0x00003066, 0x00000000,
    0x00000000, 0x8C1DD616, 0x29FEF88D, 0x1B7BECBF, 0x00000C18, 0x00000000, 0x8067B9C4,
    0x63F00C19, 0xC0F83181, 0xF16018C7, 0xC8260A81, 0x1C5CC0A0, 0x8C02A3E0, 0xF8781314,
    0x83591F80, 0x7BC60C61, 0x000C536F, 0x00000000, 0x00000000, 0xA0826000, 0xD55038EE,
    0xDFFDEAA9, 0x7FFBBF1A, 0xC5FDFFAC, 0xF25FF74A, 0x3D54EBF7, 0x141440A8, 0xB9E2FFE2,
    0x07C9E245, 0x00000257, 0x00000000, 0x00000000, 0x00000000, 0xC53218A0, 0xFFBD4374,
    0xFF77E35B, 0x2FFBA565, 0x205419F9, 0x10FFF10A, 0x00027278, 0x00000000, 0x00000000,
    0x8A643140, 0xF9EFB589, 0xC43D7E12, 0x40A79373, 0x17718736, 0xF9F8784F, 0x061044F0,
    0x3010C0C6, 0x20218000, 0x78606382, 0x871E1F28, 0x784F1771, 0x7C3F901E, 0xC3B3C43D,
    0xFF35BFFB, 0xDFA959A7, 0x0324B58C, 0x7FF88B5E, 0x07C9E144, 0x000E4803, 0x24000000,
    0xC0C2CB07, 0x40144DB8, 0x4EF928C3, 0x9FFBBF58, 0x00000000, 0xBF900183, 0x9EEB1BFB,
    0x3E752DC1, 0x2644AD31, 0x7836F26C, 0x70441478, 0x00001800, 0x2E088120, 0x0989E1E0,
    0xC0F9E4FE, 0x13F6004C, 0x9DF100F9, 0x00000BFF, 0x4C800000, 0xEB7FFB31, 0x9EA4FDBD,
    0x61B064C6, 0x001C85DF, 0x00000000, 0x50EC0000, 0xBE7BEE60, 0x9E21DEB4, 0x08FF82F6,
    0x182DFBBE, 0xB26E811E, 0x1BE3F588, 0x617B16A8, 0x3D6127A2, 0xBBFA3106, 0xE880F50F,
    0x3B3C43D9, 0x6F50AB99, 0x80E048BF, 0x5CFBC8B9, 0x9CE41790, 0x00007DE4, 0x80000000,
    0xDFE25C91, 0x97E4302A, 0x59EEF9C6, 0xB9FF7FF2, 0x032911C4, 0x00000000, 0x00000000,
    0x1F8F0000, 0xCC2EE304, 0xEB183C1F, 0x465F5889, 0x9B7BBF3D, 0x060EDEF7, 0xC90F3F85,
    0x9E24441E, 0x18464E42, 0xC8A1E4CC, 0x49CFE5C3, 0x48A7228A, 0xB050AD22, 0x16C3FA64,
    0x01883C14, 0x73AC2923, 0x3FBFF11E, 0x11BC9EFA, 0x4A2A4F7F, 0x30349FC4, 0x708B1884,
    0x6194A530, 0x8783214A, 0xFF28F0C7, 0x864432E4, 0xF878B9BF, 0x14C964B3, 0x46B6C583,
    0xF0C895C4, 0x81E91ED8, 0x8F0C7A47, 0xFE185B0B, 0xC18303C2, 0xA13C0622, 0xBBE0F4C8,
    0xF3DCE3F7, 0x621529FC, 0xF36310CD, 0x78AA4C64, 0x6A1EC2F9, 0xE1714B90, 0x0B005187,
    0x4B206A34, 0xFF85F8D1, 0x55162950, 0xFE6437B4, 0x51E1F279, 0x77BBF3C1, 0x82BBDEF1,
    0x22CD853F, 0x620D22A9, 0x1E1E3264, 0xB9B0E78A, 0xC8A0C19C, 0xA6699149, 0xB0506501,
    0x05050FE1, 0x8700C8B1, 0x50365C05, 0x0C53203C, 0x88403C50, 0xDEF7383F, 0x022BEF7B,
    0x70401128, 0xC1785DEE, 0xC1581F24, 0x84C47C0F, 0x23E0BC99, 0x09833C16, 0x1A85E25E,
    0x2FF7B9C4, 0x90056900, 0xDC7EFB18, 0x82C18961, 0x000183E7, 0xC1040300, 0x58A6B1C7,
    0xBCD86F36, 0xF8B14D61, 0x00C10438, 0x80600000, 0xC58313E7, 0x7EFFD61D, 0x00000169,
    0x00000000, 0xFBEAD200, 0x247E522F, 0x49337431, 0x00000000, 0xF54A8704, 0x652F14D2,
    0x1C9AF50C, 0x80000000, 0x7F4CD584, 0x21F94862, 0x58F7F77F, 0xDF52DCA7, 0xEE3108ED,
    0x00FD119E

  EW_FONT_KERNING_CODES( DashboardFontLightM )
  EW_FONT_KERNING_VALUES( DashboardFontLightM )
EW_END_OF_FONT_RES( DashboardFontLightM )

/* Embedded Wizard */