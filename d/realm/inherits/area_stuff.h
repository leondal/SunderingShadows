#define RA_PATH "/d/realm/"
#define RA_ROOMS RA_PATH+"rooms/"
#define RA_INHS RA_PATH+"inherits/"
#define ORS RA_ROOMS+"ao_outter_"+
#define MRS RA_ROOMS+"ao_middle_"+
#define RA_MON RA_PATH+"mon/"
#define RA_OB RA_PATH+"ob/"
//Outter Room Specific Defines
#define RA_OUTTER_I RA_INHS+"or_i"
#define RA_OR_END RA_INHS+"or_end_i"

//End Outter Room Specific Defines

//Middle Room Specific Defines
//Middle Room Hallway Specific Defines
#define RA_MR_HALL RA_INHS+"mr_hall_i"
#define RA_MR_BH RA_INHS+"mr_bh_i"
#define RA_MR_MH RA_INHS+"mr_mh_i"
#define RA_MR_FH RA_INHS+"mr_fh_i"
#define RA_MR_UFT RA_INHS+"mr_uf_tun"
#define RA_UFT_BH RA_INHS+"mr_uft_bh"
#define RA_UFT_FH RA_INHS+"mr_uft_fh"
#define RA_UFT_CH RA_INHS+"mr_uft_ch"
//End Hallway Defines

#define RA_MR_CHAM RA_INHS+"mr_cham_i"

#define MySafeRooms ({MRS"19", MRS"37", MRS"55", MRS"80", MRS"140", MRS"22"})

#define MyNoGo ({MRS"122", MRS"14", MRS"20", MRS"97", MRS"102", MRS"108", MRS"109",\
MRS"111", MRS"101", MRS"78", MRS"51", MRS"134", MRS"123", MRS"69", MRS"72"})

#define DEATH_EFFECTS_D RA_INHS+"death_effects_d"

//End Middle Room Specific Defines

#define BN1 "north button 1"
#define BN2 "north button 2"
#define LN1 "north lever 1"
#define LN2 "north lever 2"
#define BE1 "east button 1"
#define BE2 "east button 2"
#define LE1 "east lever 1"
#define LE2 "east lever 2"
#define BS1 "south button 1"
#define BS2 "south button 2"
#define LS1 "south lever 1"
#define LS2 "south lever 2"
#define BW1 "west button 1"
#define BW2 "west button 2"
#define LW1 "west lever 1"
#define LW2 "west lever 2"