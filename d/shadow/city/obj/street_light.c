inherit "/d/common/obj/misc/street_light.c";

void create(){
    ::create();
    set_short("A dark %^GREEN%^vine-covered%^MAGENTA%^ street light");
    set_dayShort("A dark %^GREEN%^vine-covered%^MAGENTA%^%^BOLD%^ street light");
    set_nightShort("%^BOLD%^%^WHITE%^A lit %^GREEN%^vine-covered%^WHITE%^ street light");
    set_long("The street light is made of wrought iron "+
    "and stands about tenfeet high.  It appears to"+
    " be an oil fueled lamp.  It lights up the streets"+
    "at night.  Oddly, vines are spiraling up the"+
    " pole and blocking out the light.");
}