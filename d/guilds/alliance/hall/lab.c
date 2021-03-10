//Minor updates to description to add in past tense, reconnected up to
//Alliance guild hall for shits and giggles.  Last change 10/17/01 - Octothorpe 1/2/09
// /d/guilds/alliance/lab.c

#include <std.h>

inherit "/std/lab";

void create()
{
    object ob;
    ::create();
    set_indoors(1);
    set_light(2);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("teleport proof", "/daemon/player_housing"->get_phouse_tp_proof("legendary"));
    set_short("Mage Lab of the Alliance");
    set_long("%^CYAN%^BOLD%^Mage Lab of the Alliance%^RESET%^\n " +
             "%^BOLD%^This room looks like nothing you have ever seen " +
             "before. It was the place where all the castle magi came to " +
             "study their spells. The walls have many different %^BLUE%^c" +
             "%^RED%^o%^BOLD%^l%^YELLOW%^o%^GREEN%^r%^MAGENTA%^s%^WHITE%^. " +
             "On the floor there is %^GREEN%^grass%^WHITE%^ growing and the " +
             "air is filled with %^YELLOW%^butterflies%^WHITE%^ that seem " +
             "to be coming from nowhere. In the middle of the room you see " +
             "an old table filled with scrolls, paper and ink. Beside the " +
             "table you see a large pot and in it some strange mixture is " +
             "boiling after all these years. At the north wall you notice " +
             "a shelf filled with many different %^ORANGE%^herbs%^BOLD%^%^WHITE%^ " +
             "and components, and on the wall beside the shelf you see a " +
             "%^MAGENTA%^painting%^WHITE%^ of the once well-respected " +
             "castle mage and you wonder who he might be.\n");
    set_listen("default", "You hear birds singing and water boiling.");
    set_smell("default", "You smell grass and herbs.");
    set_exits(([
                   "west" : "/d/guilds/alliance/hall/main",
               ]));
    set_items(([
                   "painting" : "This is the painting of the once well-known and respected castle mage called Xodor. He provided the Alliance with magical firepower and other tools, but he is mostly known for his messed up testing of new spells that often cause a disaster. This man looks really confused, you notice his bright %^BOLD%^%^BLUE%^blue%^RESET%^ hand that was the result of previous spell testings that went wrong.",
                   "pot" : "There is a boiling pot on the fire, that no one has moved aside in the last half century.  A conical-shaped sparkling mixture of granite and diamond rock, with dragon scales decorates the outside of it.  This strange construct is perfectly formed, and has a single %^BOLD%^pearl%^RESET%^ at the very top.",
               ]));
    setLabId("alliance");
    ob = new("/d/magic/obj/mirror");
    ob->move(TO);
    set_door("door", "/d/guilds/alliance/hall/main", "west", "alliance ring");
    set_open("door", 0);
    set_locked("door", 1);
    "/d/guilds/alliance/hall/main"->set_open("door", 0);
}

/*void reset() {
    object ob;
    ::reset();
    if(!present("tanoth")) {
        new("/realms/thorn/balor")->move(TO);
    }
    if(query_open("door")) {
        set_open("door",0);
        set_locked("door",1);
        "/d/guilds/alliance/hall/main"->set_open("door",0);
        ob = find_object_or_load("/d/guilds/alliance/hall/main");
        ob->set_open("door",0);
        ob->set_locked("door",1);
        tell_room(TO, "You hear the door slam shut and lock by itself.");
        tell_room(ob, "You hear the door slam shut and lock by itself.");
    }
   }*/
