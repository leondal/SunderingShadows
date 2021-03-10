//Okay, I've updated the description of this room and the method in which the king works AS
//well as the way the exit of the tomb works - you can now unlock the door with the soulcrusher
//or it will unlock itself once the king dies and I've add a random search for the rubble
//that was already in the room. -  Saide
#include <std.h>
#include "/d/deku/inherits/graveyard.h"
#define RANDSTUFF "/d/common/daemon/randstuff_d"
inherit VAULT;

object soulcrusher;
object ob, ob1;
int being_pulled, sword_pulled, searched;

void original() {
    set_long("%^BOLD%^%^BLACK%^You have entered a large above ground burial chamber.  A %^RED%^"+
    "throne%^BOLD%^%^BLACK%^ sits against the wall at the northern end and a %^RED%^decayed "+
    "corpse%^BOLD%^%^BLACK%^ rests on it.  Piles of %^RED%^rubble%^BOLD%^%^BLACK%^ litter "+
    "the floor of the chamber and a %^RESET%^small boulder%^BOLD%^%^BLACK%^ lies directly in "+
    "the center, with a %^YELLOW%^glowing sword%^BOLD%^%^BLACK%^ potruding vertically from it.  "+
    "An %^RESET%^ornate door%^BOLD%^%^BLACK%^ is inset into the southern wall of the "+
    "chamber, leading out to the graveyard.%^RESET%^");

    set_items(([
    "throne": "%^RED%^You walk up to the throne and take a good hard look.  You realize that "+
    "the corpse is wearing a golden crown.  As you look into its eyes, you get the eerie "+
    "feeling that it is waiting for something.%^RESET%^",
    "boulder" : "%^RED%^You pace around the boulder for a few minutes and see an inscription on "+
    "its side.\n\nTo Pull, perhaps to die, perhaps to conquer.\nTo Pull, to Push, perhaps to "+
    "run, perhaps to live.\nTo possess Soulcrusher is to conquer.\n",
    ({"corpse","decayed corpse"}) : "%^RED%^This corpse sits on the throne, its head is adorned "+
    "with a golden crown.  Looking into its eyes you get the eerie feeling that it is waiting "+
    "for something.%^RESET%^",
    ({"rubble","piles of rubble"}) : "%^RED%^These piles of rubble are mixtures of pieces of "+
    "stone, fragments of bone, and clumps of dirt.%^RESET%^",
    "glowing sword" : "%^YELLOW%^This sword is potruding from the boulder in the center of "+
    "the room.  Its blade is made from an adamanium with runes etched onto one side of it, "+
    "it continually gives off a dull glow.%^RESET%^",
    ] ));
    being_pulled = 0;
    sword_pulled = 0;
}

void create() {
    ::create();
    set_property("light",1);
    set_property("indoors",1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_short("%^BOLD%^%^WHITE%^Burial Chamber%^RESET%^");
    original();
    set_property("no sticks",1);
    set_property("no teleport", 1);
    set_smell("default","The smell of rot and decay is overwhelming.");
    set_exits(([
    "out" : GY_ROOMS +"grave8-4",
    ] ));
    set_search("default","%^RED%^The piles of rubble catch your attention.%^RESET%^");
    set_search("rubble",(:this_object(),"rubble_search":));
    set_door("ornate door",GY_ROOMS +"grave8-4","out","soulcrusher","lock");
    set_string("ornate door", "open", "%^RED%^The massive door swings open with a loud grating "+
    "noise.%^RESET%^");
    set_door_description("ornate door","%^BOLD%^%^WHITE%^This massive ornate door is made from "+
    "a slab of stone that has faded to a dull white over the course of time.  Painted on "+
    "it, in a blood red, is an empty throne, the crown of the one who once sat on it "+
    "laying lazily in the seat.  You realize that the throne is none other than the one "+
    "at the northern end of this chamber.%^RESET%^");
    set_locked("ornate door",0,"lock");
    set_lock_description("ornate door","lock","%^RED%^This bizarre lock has been made into the "+
    "door and the keyhole closely resembles the blade of a small sword.%^RESET%^");
    lock_difficulty("ornate door",10,"lock");
}

void rubble_search() {
    if(!objectp(TP)) return;
    if(!TP->query_invis()) {
        tell_room(TO,TPQCN+"%^RED%^ digs through a pile of rubble.%^RESET%^",TP);
    }
    if(searched == 1) {
        tell_object(TP,"%^RED%^You dig through the rubble but find nothing worthwhile.%^RESET%^");
        return;
    }
    if(random(101) > 75) {
        tell_object(TP,"RED%^You dig through the rubble and find something that might be worth "+
        "keeping!%^RESET%^");
        RANDSTUFF->find_stuff(TO,"random");
        searched = 1;
        return;
    }
    tell_object(TP,"%^RED%^You dig through the rubble but find nothing worthwhile.%^RESET%^");
    searched = 1;
    return;
}

void init() {
    ::init();
    add_action("gray_pull","pull");
    add_action("gray_push","push");
}

int gray_pull(string str) {
    if((str == "sword") || (str == "soulcrusher") || (str == "crusher")) {
        if(being_pulled == 1) {
            write("Someone else is already pulling the sword from the stone!");
            return 1;
        }
        if(sword_pulled == 1) {
            write("The sword is not within the stone.");
            return 1;
        }
        if(TP->query_paralyzed()) return notify_fail(TP->query_paralyzed_message()+"\n");
        write("You step up to the boulder, grip the sword tightly and pull.\n");
        say(TPQCN+" steps up to the boulder, grips the sword tightly and pulls.\n");
        call_out("pull_sword",4);
        TP->set_paralyzed(40,"You are pulling the sword from the boulder.");
        being_pulled = 1;
        return 1;
    }
    return 0;
}

int gray_push(string str) {
    object ob1;
    if((str == "sword") || (str == "soulcrusher") || (str == "crusher")) {
        if(present("soulcrusher", TP)) {
            ob1 = present("soulcrusher", TP);
            ob1->remove();
            call_out("push_sword", 2);
            ob = present("skeleton king");
            ob->remove();
            return 1;
        } else {
            return 0;
        }
        return 0;
    }
}

void pull_sword(string str) {
    int player_str;
    player_str = TP->query_stats("strength");

    if(player_str > random(21)) {

        tell_object(TP,"%^BOLD%^%^WHITE%^You have succeeded in pulling the sword from its "+
        "resting place.%^RESET%^\n\n");
        tell_room(TO,TPQCN + "%^BOLD%^%^WHITE%^ has succeeded in pulling the sword from its "+
        "resting place.\n\n",TP);
        TP->set_paralyzed(0);
        sword_pulled = 1;
        being_pulled = 0;
        new("/d/deku/weapons/short2")->move(TP);
        remove_item("glowing sword");
        remove_item("corpse");
        remove_item("decayed corpse");

        add_item("throne","%^YELLOW%^This throne is empty and sits against the northern wall "+
        "of the chamber.%^RESET%^");
        set_locked("ornate door",1,"lock");

        tell_object(TP,"%^RED%^Your excitement is short lived, as the once decaying corpse rises\n"+
        "from its throne to point an accusatory finger at you!%^RESET%^\n\n");
        tell_room(TO,"%^RED%^The excitement is short lived, as the once decaying corpse rises "+
        "from its throne to point an accusatory finger at "+TPQCN+"!%^RESET%^\n\n",TP);

        if(!query_open("ornate door")) {
            tell_room(TO,"%^RED%^Just as you thought things couldn't get worse a loud click echoes "+
            "through the chamber as the lock falls into place, trapping you here!%^RESET%^\n\n");
        }

        if(query_open("ornate door") == 1) {
            set_open("ornate door",0);
            tell_room(TO,"%^RED%^Just as you thought things couldn't get worse, the ornate door "+
            "slams shut and a loud click echoes through the chamber as the lock falls into place, "+
            "trapping you here!%^RESET%^\n\n");
        }

        new("/d/deku/monster/skel-king")->move(TO);
        if(ob=present("skeleton king", TO)) {
            ob->rush();
        }
        set_long("%^BOLD%^%^BLACK%^You have entered a large above ground burial chamber.  An "+
        "empty %^RED%^throne%^BOLD%^%^BLACK%^ sits against the wall at the northern end of the "+
        "chamber.  Piles of %^RED%^rubble%^BOLD%^%^BLACK%^ liter the floor of the chamber and a "+
        "%^RESET%^small boulder%^BOLD%^%^BLACK%^ lies directly in the center, with a %^RED%^slit"+
        "%^BOLD%^%^BLACK%^ in the top of it.  An %^RESET%^ornate door%^BOLD%^%^BLACK%^ is inset "+
        "into the southern wall of the chamber, leading out to the graveyard.%^RESET%^");
        return 1;
    }

    tell_object(TP,"You pull and pull, but the sword doesn't seem to budge.");
    tell_room(TO,TPQCN+" pulls and pulls, but the sword doesn't seem to budge.",TP);
    being_pulled = 0;
    return 1;
}

void monster_died() {
    tell_room(ETP, "\n\n");
    tell_room(ETP, "As you finish off the Skeleton king, a loud clicking sound echoes "+
    "through the chamber as the ornate door unlocks!");
    set_locked("ornate door",0,"lock");
}

void push_sword(string str) {
    if(!objectp(TP)) return;
    tell_object(TP,"%^RED%^As you quickly insert the sword back into the boulder, it locks \n"+
    "itself back into its familiar home.%^RESET%^\n");
    tell_room(TO,TPQCN+"%^RED%^ inserts the sword back into the boulder.\n%^RESET%^",TP);
    tell_room(TO,"%^BOLD%^%^WHITE%^The Skeleton King falls back into his resting place."+
    "%^RESET%^\n");
    original();
    set_locked("ornate door",0,"lock");
    return 1;
}

void reset() {
    ::reset();
    if(random(4) > 2) {
        original();
        searched = 0;
    }
}
