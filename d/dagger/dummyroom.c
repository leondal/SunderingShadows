// Chernobog (3/27/21)
// Dummy Room

#include <std.h>
inherit ROOM;

void create(){
    ::create();
    set_property("indoors",1);
    set_property("light",2);
    set_travel(PAVED_ROAD);
    set_terrain(CITY);
    set_climate("temperate");
    set_property("no teleport",1);
    set_property("no scry",1);
    set_name("Avatar Dummy Room");
    set_short("%^BOLD%^%^BLACK%^Avatar Dummy Room%^RESET%^");
    set_long("%^RESET%^%^CYAN%^Light from an unknown source shines down, illuminating "+
        "a small circular patch of ground. %^BOLD%^%^BLACK%^S%^RESET%^h%^BOLD%^"+
        "%^BLACK%^ad%^RESET%^o%^BOLD%^%^BLACK%^ws %^RESET%^%^CYAN%^writhe and wrap "+
        "around the edges of sight. There is a small %^YELLOW%^sign %^RESET%^%^CYAN%^"+
        "planted in the middle of the %^WHITE%^p%^BOLD%^oo%^RESET%^l of l%^BOLD%^igh"+
        "%^RESET%^t%^CYAN%^.%^RESET%^");
    set_smell("It smells like sweat and dried blood.");
    set_listen("Whispers of vicious mockery echo from the shadows.");
    set_items(([
        "sign" : "%^BOLD%^%^BLACK%^You can %^WHITE%^<retrieve dummy> %^BLACK%^to get a "+
            "dps reporting dummy, and you can %^WHITE%^<return dummy> %^BLACK%^to put "+
            "it away.%^RESET%^",
        ]));
    set_exits(([
        "lounge" : "/d/dagger/avalounge.c",
        ]));
}

void init(){
    ::init();
    add_action("retrieve_fun", "retrieve");
    add_action("return_fun", "return");
}

int retrieve_fun(string str){
    if (!str){
        return 0;
    }
    if (str == "dummy" || str == "testdummy" || str == "test dummy" || str == "practice dummy" || str == "rune"){
        if (present("testdummy")){
            tell_object(TP, "There is already a testdummy present!");
            return 1;
        }
        tell_object(TP, "You whistle and a test dummy shimmers into being.");
        tell_room(TO, "" + TPQCN + " whistles and a test dummy shimmers into being.", TP);
        switch(random(15)){
            case 0..4:
                new("/realms/chernobog/mockery/faceless_dummy.c")->move(TO);
                break;
            case 5..9:
                new("/realms/chernobog/mockery/ashra_dummy.c")->move(TO);
                break;
            case 10..14:
                new("/realms/chernobog/mockery/kismet_dummy.c")->move(TO);
                break;
            default:
                new("/realms/chernobog/mockery/faceless_dummy.c")->move(TO);
                break;
        }
        return 1;
    }
    return 0;
}

int return_fun(string str){
    if (!str){
        return 0;
    }
    if (str == "dummy" || str == "testdummy" || str == "test dummy" || str == "practice dummy"){
        object dummyobj;
        if (!present("test dummy")) {
            tell_object(TP, "There is no practice dummy to return!");
            return 1;
        }
        tell_object(TP, "You kick the test dummy in the junk and it fades out of existence.");
        tell_room(TO, "" + TPQCN + " kicks the test dummy in the junk and it fades out of existence.", TP);
        dummyobj = present("test dummy");
        if (objectp(dummyobj)){
            dummyobj->move("/d/shadowgate/void");
            dummyobj->remove();
        }
        return 1;
    }
    return 0;
}