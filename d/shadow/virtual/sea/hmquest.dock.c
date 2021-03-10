#include <std.h>
inherit DOCK;

int is_virtual() { return 1; }
int is_water() { return 1; }
int is_dock() { return 1; }

void create(){
    ::create();
    set_property("light", 2);
    set_property("indoors", 0);
    set_property("no teleport", 1);
    set_terrain(BARREN);
    set_travel(DECAYED_FLOOR);
    set_name("An ancient pier");
    set_short("%^RESET%^%^ORANGE%^An ancient pier%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^An ancient pier%^RESET%^\n"
"%^RESET%^You have stepped from the boat onto an old, decrepit pier.  The %^ORANGE%^woo%^BOLD%^%^BLACK%^de%^RESET%^%^ORANGE%^n %^RESET%^planks shift beneath your feet, groaning as "
"much with your weight as with the constant pulse of %^BLUE%^w%^BOLD%^%^BLUE%^a%^BOLD%^%^CYAN%^v%^BOLD%^%^WHITE%^e%^RESET%^%^CYAN%^s %^RESET%^that threaten to pull it beneath at any moment.  "
"Away to the northwest, above the %^BOLD%^%^BLACK%^r%^RESET%^oc%^BOLD%^%^BLACK%^k%^RESET%^y c%^ORANGE%^l%^RESET%^if%^BOLD%^%^BLACK%^f%^RESET%^s upon the highest point of this tiny island, the "
"upper reaches of a tall %^BLUE%^building %^RESET%^loom above the treeline.  A crumbling set of stairs might once have offered access directly to the building, though they seem too damaged now "
"to offer such direct access.  Off to the southeast spreads a stretch of %^YELLOW%^g%^BOLD%^%^WHITE%^o%^RESET%^l%^ORANGE%^d%^YELLOW%^e%^BOLD%^%^WHITE%^n %^RESET%^sand, spotted with straggling "
"patches of %^BOLD%^%^GREEN%^g%^WHITE%^r%^BOLD%^%^GREEN%^a%^RESET%^%^GREEN%^s%^BOLD%^%^GREEN%^s%^RESET%^.  Occasionally %^BOLD%^%^WHITE%^birds %^RESET%^can be seen passing overhead, one of the "
"few signs of life on this apparently desolate island.\n");

    set_smell("default","The salty tang of the sea can't quite overpower the stench of rotted wood.");
    set_listen("default","The pier creaks and groans beneath the relentless pounding of the surf.");
    set_exits( ([
        "southeast" : "/d/hm_quest/rooms/quest2"
    ]) );
    set_items(([
      ({ "cliffs", "building", "stairs", "crumbled stairs", "rocky cliffs" }) : "%^RESET%^An %^BLUE%^omin%^GREEN%^o%^BLUE%^us %^RESET%^building of stone looms over the treeline far above you, "
"its walls cracked and darkened with age, while %^GREEN%^moss %^RESET%^and %^BOLD%^%^GREEN%^v%^YELLOW%^i%^BOLD%^%^GREEN%^nes %^RESET%^climb as they will upon its every surface.  A series of "
"crumbling stairs leads up the %^BOLD%^%^BLACK%^r%^RESET%^oc%^BOLD%^%^BLACK%^k%^RESET%^y c%^ORANGE%^l%^RESET%^iff%^BOLD%^%^BLACK%^s%^RESET%^ide towards it, though both building and staircase "
"appear to have seen better days, and you decide against risking your neck to try climbing them.",
      "pier" : "%^RESET%^The pier you stand upon feels treacherous at best, its %^ORANGE%^woo%^BOLD%^%^BLACK%^de%^RESET%^%^ORANGE%^n %^RESET%^planks creaking and shifting as place your feet.  "
"The constant surge of %^BLUE%^w%^BOLD%^%^BLUE%^a%^BOLD%^%^CYAN%^v%^BOLD%^%^WHITE%^e%^RESET%^%^CYAN%^s %^RESET%^against its pillars causes the rotting wood to groan constantly.  You suspect "
"you'd feel far safer standing on solid ground.",
      ({ "beach", "sand", "grass" }) : "%^RESET%^Stretching away from the pier and the rocky peninsula it seems tenuously secured to, is a stretch of pristine golden sand.  Sparkling %^BLUE%^w"
"%^BOLD%^%^BLUE%^a%^BOLD%^%^CYAN%^v%^BOLD%^%^WHITE%^e%^RESET%^%^CYAN%^s %^RESET%^constantly crash and break at its edge, adding a constant dull roar of sound.  Patches of straggling grass dot "
"the inner edges of the beach, before it is lost entirely to the line of trees and foliage further inland.",
      "birds" : "%^RESET%^A %^BOLD%^%^WHITE%^wh%^RESET%^it%^BOLD%^%^WHITE%^e-w%^RESET%^i%^BOLD%^%^WHITE%^nged %^RESET%^bird occasionally wheels overhead, its scream almost lost beneath the "
"constant pounding of the %^BLUE%^w%^BOLD%^%^BLUE%^a%^BOLD%^%^CYAN%^v%^BOLD%^%^WHITE%^e%^RESET%^%^CYAN%^s%^RESET%^.  There doesn't seem to be any other sign of habitation here.",
    ]));
    add_pre_exit_function("southeast","GoThroughDoor");
}

int GoThroughDoor() {
    if(avatarp(TP)) return 1;
    if(member_array("Quest for the Swords",TP->query_quests())!=-1) {
        tell_object(TP,"A feeling of disinterest fills you as you realise you have no further purpose here.");
        tell_room(TO,"You see "+TP->QCN+" go to step off the pier, before pausing and simply shrugging in disinterest.",TP);
        return 0;
    }
    if(TP->query_base_character_level()<19) {
        tell_object(TP,"A feeling of dread fills you as you go to step upon the island, and something within you shudders back from a challenge far too great yet!");
        tell_room(TO,"You see "+TP->QCN+" stop dead in "+TP->QP+" tracks, deciding better of stepping onto the island.",TP);
        return 0;
    }
    if(!TP->query("which_hm_quest")) {
        tell_object(TP,"A feeling of disinterest fills you as you realise you have no purpose here.");
        tell_room(TO,"You see "+TP->QCN+" go to step off the pier, before pausing and simply shrugging in disinterest.",TP);
        return 0;
    }
    return 1;
}