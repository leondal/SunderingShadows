#include <std.h>
inherit OBJECT;
int charges;
int xx;
int FLAG;
void create() {
    ::create();
    set_name("wand");
    set("id",({"wand","wand of wonder"}));
    set("short",
	"Wand of "
	"%^BLUE%^w%^WHITE%^o%^RED%^n%^YELLOW%^d"
	"%^MAGENTA%^e%^GREEN%^r%^RESET%^"
    );
    set(
	"long","This wand is has many wonderful multi-coloned runes "
	"emblazoned upon it. You can determine from the runes you "
	"simply aim it at your target."
    );
    set_value(200);
    set_weight (10);
    charges=random(35)+5;
}
void init() {
    ::init();
    add_action("aim_func","aim");
}
int aim_func(string str) {
    string who;
    object ob;
    if(!str) {
	notify_fail("Syntax: aim wand at <target>\n");
	return 0;
    }
    if (TP->query_bound() || TP->query_unconscious()) {
       TP->send_paralyzed_message("info",TP);
       return 1;
    }
    if(!query_wielded()) return notify_fail("Wield it first?\n");

    if(sscanf(str,"wand at %s",who)!= 1) {
        notify_fail("Syntax: aim wand at <target>\n");
	return 0;
    }
    if(!(ob=present(who,environment(TP)))) {
	notify_fail("You must have a valid target.\n");
	return 0;
    }	
    if(charges<1) {
	tell_object(TP,"The wand is burned out now.\n");
	return 1;
    }
    if(FLAG == 1) {
	tell_object(TP,"The wand is still recharging.");
        return 1;
    } else {
	FLAG = 1;
	call_out("endfunc",7);
	charges = charges - 1;
	tell_room(ETP,
            "%^RED%^%^BOLD%^"+TPQCN+" glances around slyly, cackles "
	    "insanely, and suddenly points a strange wand at "
	    +ob->query_cap_name()+"!%^RESET%^\n"
 	,({TP,ob}));
	tell_object(TP,
	    "%^RED%^%^BOLD%^You feel haphazordous and insane and decide "
	    "to point the strange and wonderous wand at "
	    +ob->query_cap_name()+"!%^RESET%^\n"
	);
	tell_object(ob,
	    "%^BOLD%^%^RED%^You see "+TPQCN+" cackle madly while pointing "
	    "a strange wand towards you!%^RESET%^\n"
	);
        xx=random(10)+1;
//
// RANDOM EFFECT ROUTINE BEGINS HERE
//
        switch(xx) {
	case 1:
            tell_room(ETP,
		"%^BOLD%^%^YELLOW%^Suddenly a stream of "
		"%^MAGENTA%^butterflys%^BOLD%^%^YELLOW%^ fly out of "+TPQCN+
		"'s wand towards "+ob->query_cap_name()+"!\n%^RESET%^"
            ,({TP,ob}));
            tell_object(TP,
		"%^YELLOW%^%^BOLD%^Suddenly a stream of "
		"%^MAGENTA%^butterflys%^BOLD%^%^YELLOW%^ fly out of "
		"your wand at "+ob->query_cap_name()+"!%^RESET%^\n"
            );
    	    tell_object(ob,
		"%^YELLOW%^%^BOLD%^Suddenly a stream of "
		"%^MAGENTA%^butterflys%^BOLD%^%^YELLOW%^ fly out of "+TPQCN+"'s "
		"wand towards you!%^RESET%^\n"
    	    );
    	    return 1;
	case 2:
            tell_room(ETP,
		"%^YELLOW%^A bolt of lightning streaks forth from "+TPQCN+
		"'s wand and strikes "+ob->query_cap_name()+"!%^RESET%^\n"
            ,({TP,ob}));
            tell_object(TP,
		"%^YELLOW%^A bolt of lightning streaks forth from your wand "
		"and you grin as it strikes "+ob->query_cap_name()+"!%^RESET%^\n"
            );
            tell_object(ob,
		"%^YELLOW%^A bolt of lightning streaks forth from "+TPQCN+
		"'s wand and strikes you badly!%^RESET%^\n"
            );
    	    if(!ob->kill_ob(TP,0)) TP->kill_ob(ob,0);
    	    if("daemon/saving_d"->saving_throw(ob,"rod_staff_wand")) {
	        ob->do_damage("torso",roll_dice(6,6));
            } else {
        	ob->do_damage("torso",((roll_dice(6,6))/2));
            }
            return 1;
    case 3:
    tell_room(ETP,
	"%^GREEN%^%^BOLD%^A strange ray leaves the wand held by "+TPQCN+
	" and %^RESET%^%^GREEN%^grass%^BOLD%^%^GREEN%^ grows rapidly "
	"everywhere around "+ob->query_cap_name()+"!%^RESET%^\n"
    ,({TP,ob}));
    tell_object(TP,
	"%^GREEN%^%^BOLD%^A strange ray leaves your wand and "
	"mysteriously %^RESET%^%^GREEN%^grass%^GREEN%^%^BOLD%^ grows "
	"all around "+ob->query_cap_name()+"!%^RESET%^\n"
    );
    tell_object(ob,
	"%^GREEN%^%^BOLD%^A strange ray leaves "+TPQCN+
	"'s wand and %^RESET%^%^GREEN%^grass%^BOLD%^%^GREEN%^ grows "
	"rapidly all around you!%^RESET%^\n"
    );
    return 1;
case 4:
      if(ob->query_property("no paralyze")) {
         tell_room(ETP,"%^BOLD%^The wand's magic disperses futilely around "+ob->query_cap_name()+".",ob);
         tell_object(ob,"%^BOLD%^The wand's magic disperses futilely around you.");
         return 1;
      }
    tell_room(ETP,
	"%^BOLD%^%^BLACK%^A strange %^WHITE%^cackle%^BLACK%^ fills "
	"the air and suddenly "+ob->query_cap_name()+" begins "
	"%^YELLOW%^laughing incoherently %^BLACK%^and is unable "
	"to move!%^RESET%^\n"
    ,({TP,ob}));
    tell_object(TP,
	"%^BOLD%^%^BLACK%^You point the wand and a strange "
	"%^WHITE%^cackle%^BLACK%^ fills the air and suddenly "
	+ob->query_cap_name()+" begins %^YELLOW%^laughing "
	"incoherently %^BLACK%^and is unable to move!%^RESET%^\n"
    );
    tell_object(ob,
	"%^BLACK%^%^BOLD%^A strange %^WHITE%^cackle%^BLACK%^ fills "
	"the room and grips your mind! You begin to laugh hysterically "
	"and are unable to move!%^RESET%^\n"
    );
    if(!ob->kill_ob(TP,0)) TP->kill_ob(ob,0);
    if("daemon/saving_d"->saving_throw(ob,"rod_staff_wand")) {
        ob->set_paralyzed(50,"You are still laughing like a fool!");
    } else {
        tell_object(ob,
	    "%^BOLD%^%^BLACK%^However, you quickly calm down.%^RESET%^\n"
	);
    }
    return 1;
case 5:
    tell_room(ETP,
	"%^RED%^%^BOLD%^Balls of flames erupt in "+TPQCN+"'s hands causing "
	+TPQCN+" to scream in pain! "+TPQCN+" quickly throws the balls of "
	"flame at "+ob->query_cap_name()+" who screams a little louder than "
	+TPQCN+" ever did!%^RESET%^\n"
    ,({TP,ob}));
    tell_object(TP,
	"%^BOLD%^%^RED%^Balls of flames erupt in your hands causing "
	"you to scream in pain! You quickly, as the flames grow larger, "
	"decide to throw them at "+ob->query_cap_name()+" who screams a "
	"lot louder than you did .%^RESET%^\n"
    );
    tell_object(ob,
	"%^BOLD%^%^RED%^"+TPQCN+" screams in pain as balls of flames "
	"erupt in "+TP->QP+" hands! However "+TP->QS+" hurls the balls "
	"at you causing you to scream a lot louder than "+TP->QS+
	" ever did.%^RESET%^\n"
    );
    if(!ob->kill_ob(TP,0)) TP->kill_ob(ob,0);
    ob->do_damage("torso",roll_dice(5,4));
    TP->do_damage("torso",roll_dice(2,4));
    return 1;
case 6:
    tell_room(ETP,
	"%^CYAN%^"+TPQCN+" points a wand at "+ob->query_cap_name()+
	" and a look of satisfaction and triumph crosses "+TP->QP+
	"'s face. You don't know what they are grinning about however, "
	"the wand did absolutely nothing.%^RESET%^\n"
    ,({TP,ob}));
    tell_object(TP,
	"%^BOLD%^%^YELLOW%^You point the wand at "
	+ob->query_cap_name()+" and a %^BOLD%^%^RED%^pillar of "
	"fire%^YELLOW%^ spews forth from the ground and totally surrounds "
	+ob->query_cap_name()+" causing them to scream in total and utter "
	"agony!!!%^RESET%^\n"
    );
    tell_object(ob,
	"%^CYAN%^"+TPQCN+" points the wand at you and a look of triumph "
	"and satisfaction crosses their face. You have no clue what they "
	"are grinning about because the wand did nothing. Perhaps you "
	"better play along.%^RESET%^/n"
    );
    if(!ob->kill_ob(TP,0)) TP->kill_ob(ob,0);
    return 1;
case 7:
    tell_room(ETP,
	"%^BLUE%^It begins to rain heavily in the area and "
	"%^BOLD%^%^BLACK%^thunder%^RESET%^%^BLUE%^ and "
	"%^BOLD%^%^YELLOW%^lightning%^RESET%^%^BLUE%^ fill the air above "
	+ob->query_cap_name()+"!%^RESET%^\n"
    ,({TP,ob}));
    tell_object(TP,
	"%^BLUE%^You point the wand and it begins to rain heavily in the "
	"area as %^BOLD%^%^BLACK%^thunder%^RESET%^%^BLUE%^ and "
	"%^BOLD%^%^YELLOW%^lightning%^RESET%^%^BLUE%^ fill the air above "
	+ob->query_cap_name()+"!%^RESET%^\n"
    );
    tell_object(ob,
	"%^BLUE%^It begins to rain heavily in the area and "
	"%^BOLD%^%^BLACK%^thunder%^RESET%^%^BLUE%^ and "
	"%^BOLD%^%^YELLOW%^lightning%^RESET%^%^BLUE%^ fill the air "
	"above you!%^RESET%^\n"
    );
    return 1;
case 8:
    tell_room(ETP,
	"%^WHITE%^%^BOLD%^A %^YELLOW%^glowing light%^WHITE%^ shoots "
	"from the tip of the wand and draws %^BLUE%^life energy%^WHITE%^ "
	"from "+ob->query_cap_name()+" and %^RED%^emblazons%^WHITE%^ it "
	"to "+TPQCN+"!%^RESET%^\n"
    ,({TP,ob}));
    tell_object(TP,
	"%^WHITE%^%^BOLD%^A %^YELLOW%^glowing light%^WHITE%^ shoots "
	"from the tip of your wand and draws %^BLUE%^life "
	"energy%^WHITE%^ from "+ob->query_cap_name()+" to you!%^RESET%^\n"
    );
    tell_object(ob,
	"%^WHITE%^%^BOLD%^"+TPQCN+" points the wand at you and you are "
	"hit by a %^YELLOW%^glowing light%^WHITE%^ which draws "
	"the %^BLUE%^life energy%^WHITE%^ from you to "+
	TP->QO+"!%^RESET%^\n"
    );
    if(!ob->kill_ob(TP,0)) TP->kill_ob(ob,0);
    ob->do_damage("torso",(10));
    TP->do_damage("torso",(-10));
    return 1;
case 9:
      if(ob->query_property("no paralyze")) {
         tell_room(ETP,"%^BOLD%^The wand's magic disperses futilely around "+ob->query_cap_name()+".",ob);
         tell_object(ob,"%^BOLD%^The wand's magic disperses futilely around you.");
         return 1;
      }
    tell_room(ETP,
	"%^BOLD%^%^MAGENTA%^"+TPQCN+" and "
	+ob->query_cap_name()+" suddenly become %^RED%^frozen "
	"%^CYAN%^in %^BLUE%^time %^MAGENTA%^while the world around "
	"them both continues to keep moving!%^RESET%^\n"
    ,({TP,ob}));
    tell_object(TP,
	"%^MAGENTA%^%^BOLD%^You and "+ob->query_cap_name()+
	" suddenly become %^RED%^frozen %^CYAN%^in %^BLUE%^time "
	"%^MAGENTA%^while the world continues to keep moving "
	"around you!%^RESET%^\n"
    );
    tell_object(ob,
	"%^MAGENTA%^%^BOLD%^You and "+TPQCN+" are suddenly "
	"%^RED%^frozen %^CYAN%^in %^BLUE%^time %^MAGENTA%^while the "
	"world continues to keep moving around you!%^RESET%^\n"
    );
    ob->set_paralyzed(random(50)+10,
	"%^BOLD%^%^BLACK%^You are frozen in time.%^RESET%^"
    );
    TP->set_paralyzed(random(30)+10,
	"%^BOLD%^%^BLACK%^You are frozen in time.%^RESET%^"
    );
    if(!ob->kill_ob(TP,0)) TP->kill_ob(ob,0);
    return 1;
case 10:
    tell_room(ETP,
	"%^BOLD%^%^CYAN%^"+TPQCN+" is suddenly surrounded by "
	"%^WHITE%^three glowing angels%^CYAN%^ who briefly "
	"%^YELLOW%^sing a hymn%^CYAN%^.\n%^BLUE%^"+TPQCN+
	" looks refreshed!%^RESET%^\n"
    ,({TP,ob}));
    tell_object(TP,
	"%^BOLD%^%^CYAN%^You are suddenly surrounded by "
	"%^WHITE%^three glowing angels%^CYAN%^ who briefly %^YELLOW%^sing "
	"a hymn%^CYAN%^.\n%^BLUE%^You are refreshed!%^RESET%^\n"
    );
    tell_object(ob,
	"%^BOLD%^%^CYAN%^"+TPQCN+" is suddenly surrounded by "
	"%^WHITE%^three glowing angels%^CYAN%^ who briefly "
	"%^YELLOW%^sing a hymn%^CYAN%^.\n%^BLUE%^"+TPQCN+
	" looks refreshed!%^RESET%^\n"
    );
    TP->do_damage("torso",-20+random(5));
        return 1;
        }
// 
// HERE ENDS THE RANDOM FUNCTIONS OF THE WAND
//
        if(charges<1) {
    	    set_short("A wand(broken)");
    	    set_long("The wand is broken and useless now.\n");
        }
    }
}
void endfunc() {
    FLAG = 0;
}
