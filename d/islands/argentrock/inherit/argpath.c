// Altered to use CROOM by Ares - 3-22-05
// added color and fixed bug where traps hit imms
// -hades 2/7/12
// added outpost ambusher and cache - Yves 2/15/18
#include <std.h>
#include "../argabbr.h"
#include <daemons.h>

inherit CROOM;

void make_creatures();

string iden;
int mobs,cplant_avai,trap_located,searched;
object room;

void create() {

    mobs = random(15);

    ::create();
    set_terrain(HEAVY_FOREST);
    set_travel(GAME_TRACK);
    set_property("light",2);

    set("short","A path in Argentrock Forest");
    set("day long","%^BOLD%^%^GREEN%^A path in Argentrock Forest%^RESET%^\n"
        "You are walking along a small %^GREEN%^path%^RESET%^ buried deep inside the Argentrock "
        "Forest. %^GREEN%^Trees%^RESET%^ rise stories high above you. %^GREEN%^Grass%^RESET%^ almost covers "
        "the path. Some %^CYAN%^flowers%^RESET%^ and %^ORANGE%^mushrooms%^RESET%^ grow by the trees. Only a few "
        "rays of sunlight sneak through the thick canopy of trees.");

    set("night long","%^GREEN%^A path in Argentrock Forest%^RESET%^\n"
        "You are walking along a small %^GREEN%^path%^RESET%^ buried deep inside the Argentrock "
        "Forest. %^GREEN%^Trees%^RESET%^ rise stories high above you. %^GREEN%^Grass%^RESET%^ almost covers "
        "the path. You can still see some %^CYAN%^flowers%^RESET%^ and %^ORANGE%^mushrooms%^RESET%^ grow by the "
        "trees in the dark. Fireflies lighten up the night a bit.");

    set_items( (["path":"It is almost covered by grass.",
        "trees":"You cannot identify what kind of trees they are.",
        "grass":"Very ordinary grass.",
         ({"flowers","mushrooms"}):"This vegetation you see almost "+
            "everywhere."]) );

    set_smell("default","Fresh breaths of the forest restore you.");
    set_listen("default","You hear gusts of wind blow through the forest.");

    set_exits( (["south":PATH+"argpath10"]) );

}

void make_creatures()
{
    string *exits;
    string pick;
    object *allmons,mon;
    int i,monsters;

    monsters = has_mobs();

    if(!monsters && !present("argmon") && !trap_located)
    {
        if(mons) { mons = ([]); }

        if(!random(4))
        {
            exits = (string *)TO->query_exits();
            if(!sizeof(exits)) { return; }
            pick = exits[random(sizeof(exits))];

            switch(random(4))
            {
            case 0:
                add_item("ground","You didn't notice anything, maybe you "
                    "should search it more carefully.");
                add_item("thread","This is probably a trap!");
                set_search("ground","You find a silk thread leading towards "
                    "the trees at "+pick+".");
                set_trap_functions(({pick}),({"headless"}),({pick}));
                trap_located = 1;
                iden = "headless&"+pick;
                break;
            case 1:
                add_item("ground","You notice that the leaves on ground to "
                    "the "+pick+" are mostly fresh and green.");
                trap_located = 1;
                set_trap_functions( ({pick}),({"elft"}),({pick}) );
                iden = "elft&"+pick;
                break;
            case 2:
                cplant_avai = 1;
                add_item("plant","As you concentrate on the plant to the "+
                    pick+", you notice that some leaves resemble something's "
                    "teeth!");
                trap_located = 1;
                set_pre_exit_functions( ({pick}),({"trap_them"}) );
                iden = "cplant&"+pick;
                break;
            case 3:
                searched = 0;
                pick = "down";
                add_item("foliage","The foliage seems to be hiding something.");
                set_search("foliage",(:TO,"foliage_func":));
                trap_located = 1;
                iden = "cache&"+pick;
                break;
            }
            return;
        }
        else
        {
            switch(random(23))
            {
            case 0..2:
                set_monsters( ({MON"fmammoth"}),({1}) );
                break;
            case 3:
                set_monsters( ({MON"cwyrm"}),({1}) );
                break;
            case 4..5:
                set_monsters( ({MON"tbasilisk"}),({1}) );
                break;
            case 6..10:
                set_monsters( ({MON"erider"}),({roll_dice(1,2)}) );
                break;
            case 11..15:
                set_monsters( ({MON"ambusher"}),({roll_dice(1,2)}) );
                break;
            case 16..22:
                break;
            }
            return;
        }
    }
    return;
}

int headless() {
    string verb;
    object mon;
    int num,i;
    if(!objectp(TP)) return 1;
    verb = query_verb();
    remove_item("ground");
    remove_item("thread");
    remove_search("ground");
    tell_room(TO,"%^BOLD%^BLUE%^As "+TPQCN+" wanders "+verb+", "+
        TP->query_subjective()+" trips over a silk thread and a wooden "+
        "cage drops from above.",TP);
    tell_object(TP,"%^BOLD%^BLUE%^As you walk "+verb+", you trip over a "+
        "silk thread and a wooden cage drops from above.");
    tell_room(TO,"%^BOLD%^RED%^The wooden cage drops right on "+TPQCN+", "+
        "hitting "+TP->query_objective()+" right on the head and traps "+
        TP->query_objective()+" within.",TP);
    tell_object(TP,"%^BOLD%^RED%^The wooden cage drops right on you, "+
        "hitting you right on your head and traps you within.");
    TP->set_paralyzed(20,"You are still trapped within the wooden cage "+
        "and cannot move freely!");
    TP->do_damage( "head",roll_dice(3,10) );
    TP->add_attacker(TO);
    TP->continue_attack();
    num = roll_dice(1,3);
    for(i = 0;i < num;i++){
        mon= new(MON+"headless");
        mon->move(TO);
        mon->kill_ob(TP,1);
    }
    tell_room(TO,"%^BOLD%^WHITE%^A pack of headless rush out of the "+
        "trees to hunt their prey.");
    trap_located = 0;
    toggle_trap(verb);
    return 1;
}

int elft() {
    string verb;
    object *inven,mon,obj;
    int all,i,j,k,l,spear_num,num;
    if(!objectp(TP)) return 1;
    verb = query_verb();
    remove_item("ground");
    tell_room(TO,"%^BOLD%^WHITE%^As "+TPQCN+" wanders "+verb+" the ground "+
        "shakes and some spears shoot out at all directions from beneath "+
        TP->query_objective()+"!",TP);
    tell_object(TP,"%^BOLD%^WHITE%^As you walk "+verb+" the ground shakes "+
        "and some spears shoot out at all directions from beneath you!");
    tell_object(TP,"%^BOLD%^RED%^The spears are too close, you cannot "+
        "avoid them.");

    TP->do_damage( "torso",
    roll_dice( 3,38 - (int)TP->query_stats("dexterity") ) );
    TP->add_attacker(TO);
    if(objectp(TP)) { TP->continue_attack(); }
    if(objectp(TP)) { TP->remove_attacker(TO); }
    inven = filter_array(all_living(TO),"is_non_immortal",FILTERS_D);
    all = sizeof(inven);
    if(all > 2)
        all = 2;
    num = roll_dice(all,2);
    if(num > 4)    //this should not happen
        num = 4;
    for(i = 0;i < num;i++){
        mon = new(MON+"elft");
        mon->move(TO);
        for(j = 0;j < all;j++) {
        mon->kill_ob(inven[j],1);
      }
    }
    inven -= ({TP});
    all = sizeof(inven);
    obj = new(OBJ+"spear");
    spear_num = random(2) + 3;
    for(k = 0;k < all;k++) {
        for(l = 0;l < spear_num;l++) {
            if( TO->Thaco(1,inven[k],obj) < (random(20) + 10) ) {
                tell_object(inven[k],"A spear hits you!");
                tell_room(TO,"A spear hits "+inven[k]->query_cap_name()+"!",
                    inven[k]);
                mon->do_hits(inven[k],obj,"torso");
            }
        }
    }
    tell_room(TO,"%^BOLD%^CYAN%^A group of fey'ri appear from the trees to "+
        "capture their prey!!");
    trap_located = 0;
    toggle_trap(verb);
    return 1;
}

int trap_them() {
    string verb;
    object mon;
    verb = query_verb();
     if(!objectp(TP)) return 1;
    if( present("plant") ) {
        tell_object(TP,"%^BOLD%^GREEN%^The Carnivorous plant won't let you "+
            "leave "+verb+".");
        return 0;
    }
    if(cplant_avai == 1) {
        tell_object(TP,"%^BOLD%^RED%^As you attempt to leave "+verb+", you "+
            "suddenly feel that something bites you in the leg!");
        tell_room(TO,"%^BOLD%^RED%^As "+TPQCN+" attempts to leave "+
            verb+", something bites "+TP->query_objective()+" in the leg!",
            TP);
        mon = new(MON+"cplant");
        mon->move(TO);
        mon->kill_ob(TP,1);
        remove_item("plant");
        cplant_avai = 0;
        TP->do_damage( "left leg",roll_dice(3,10) );
        trap_located = 0;
        return 0;
    }
    return 1;
}

int foliage_func(){
    if(searched){
        tell_object(TP,"The cache is already exposed.");
        return 0;
    }
    if(!objectp(room)){
        room = new(PATH+"cache");
        room->add_exit(file_name(TO),"up");
    }
    tell_room(TO,""+TPQCN+" finds a hidden underground cache!",TP);
    tell_object(TP,"You find a hidden underground cache!");
    add_exit(file_name(room),"down");
    searched = 1;
    return 1;
}

string query_long(string str){
   string desc,kind,pick;
   desc = ::query_long(str);
   if(!iden)
      return desc;
   if(trap_located == 0)
      return desc;
   sscanf(iden,"%s&%s",kind,pick);
   if( !kind )
      return desc;
   switch (kind){
      case "headless":
          desc += " A flash of light from the ground catches your eye.";
         return desc;
         break;
      case "elft":
         desc += " Some strange leaf pattern on the ground attracts your "+
            "attention.";
         return desc;
         break;
      case "cplant":
         desc += " A plant here is odd.";
         return desc;
         break;
     case "cache":
        desc += " The foliage here is especially thick.";
        return desc;
        break;
   }
   return desc;
}
