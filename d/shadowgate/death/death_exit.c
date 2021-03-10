/* Note:  death_exit_offestry.c is used (and inherits this but adds the Offestry church as an exit) if the PC's highest level is below 7.  Added to solve the problem of newbies who find their trainer in the newbie area and die before having found their way out or any other cities  *Styx*  5/18/03
*/

#include <std.h>

#define OFFESTRY_CHURCH "/d/newbie/rooms/town/church"
inherit "/d/shadowgate/death/death_inherit";

void create() {
    ::create();
    set_short("The gate to the etherial plane");
    set_property("light", 2);
    set_property("no teleport", 1);
    set_property("indoors", 1);
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_long(
            "%^WHITE%^%^BOLD%^Beyond the Veil%^RESET%^
%^RED%^%^BOLD%^A letters of tongue unknown %^ORANGE%^b%^BOLD%^%^RED%^u%^ORANGE%^rn%^RED%^ in front of you:
%^BOLD%^%^%^TO MOVE ON, CHOOSE THE EXIT THAT LEADS TO THE CHURCH THAT YOU WISH TO RETURN TO AND YOU SHALL MOVE THERE. BEWARE: THIS GATEWAY IS ONE WAY.%^RESET%^
"
            );
    set_smell("default", "You smell nothing in the void.");
    set_listen("default", "You hear nothing in the void.");
    set_exits( ([
                "shadow" : "/d/shadow/city/room/church",
                "tharis" : "/d/tharis/newtharis/rooms/tharis_church1.c",
                "eldebaro" : "/d/islands/common/eldebaro/newrooms/church",
                "kinaro" : "/d/dagger/kinaro/church",
                "seneca" : "/d/attaya/newseneca/rooms/cath_nave",
                "graez" : "/d/undead/rooms/town/church1",
                "asgard" : "/d/laerad/parnelli/asgard/as72",
                "antioch" : "/d/antioch/wild/forest/chapel_out",
                "azha" : "/d/azha/town/church",
                "deku" : "/d/deku/town/church",
                "tonovi" : "/d/dagger/tonovi/town/temple1",
                "juran" : "/d/shadow/juran/city/church",
                "lothwaite" : "/d/barriermnts/lothwaite/rooms/chapel5",
                "nurval" : "/d/dagger/nurval/room/shrine",
                "torm" :  "/d/dagger/Torm/city/c101b",
                "tabor" : "/d/darkwood/tabor/room/church",
                "muuldaan" : "/d/shadow/room/muuldaan/rooms/church",
                "ice" : "/d/islands/elf/church",
                "temple" : "/d/shadow/room/city/church",
                "accept" : "/d/shadow/room/city/church",
                "cancel" : "/d/shadow/room/city/church",
                ]) );

    set_invis_exits(({"accept","cancel"}));
    set_pre_exit_functions(({"accept","cancel","temple"}),({"get_the_verb","get_the_verb","pick_temple"}));

}

void init()
{
    string waswhere = "";
    object newbie_church;
    ::init();
    attempt_raise();
    if(TP->query_ghost()) { TP->set_hp(1); }
    waswhere = arrange_string(base_name(TP->get_static("died_here")),10);
    if(newbiep(TP) || ( waswhere == arrange_string(OFFESTRY_CHURCH,10) ) )
    {
        write("%^BOLD%^%^RED%^Because you are still a newbie, you feel a force whisk you away to where you belong.");
        newbie_church = find_object_or_load(OFFESTRY_CHURCH);
        if(!objectp(newbie_church)) tell_object(TP, "For some reason the newbie church appears, broken, attemping to fix.");
        TP->move_player(newbie_church);
        return;
    }
    if(TP->get_perma_death() > time() && ((object)TP->query_last_location()) == find_object_or_load("/d/shadowgate/death/death_room"))
    {
        TP->dead_quit();
    }
}

int pick_temple(string str)
{
    string diety;
    diety = (string)TP->query_diety();
    if(!stringp(diety) || diety == "" || diety == " " || diety == "godless")
    {
        tell_object(TP,"You are faithless, you have no temple to return to.");
        return 0;
    }
    diety = replace_string(diety," ","_");
    if(file_exists("/d/magic/temples/"+diety+"/"+diety+".c"))
    {
        TP->move("/d/magic/temples/"+diety+"/"+diety+"");
        TP->describe_current_room(1);
        return 0;
    }
    return 0;
}
