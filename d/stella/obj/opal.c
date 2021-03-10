//    A Scrying Item
//
//    by Killashandra

#include <std.h>
inherit "/std/armour";
int uses;
// int FLAG;   flag variable not used as far as I can tell *Styx*  9/27/03 last chg. 2/26/03
string maindir;


create() {
    ::create();
//    FLAG = 0;  *Styx*  9/27/03 last chg. 2/26/03
    uses = random(3)+2;
    set_name("opal bracelet");
    set_id(({"bracelet","opal bracelet","opal"}));
    set_short("%^WHITE%^%^BOLD%^Opal %^YELLOW%^Bracelet%^RESET%^");
    set_long(
        "%^RESET%^%^BLUE%^This is a fine %^YELLOW%^gold filigree "
      "%^RESET%^%^BLUE%^"
	"bracelet with a large %^WHITE%^Opal%^BLUE%^ "
        "set into the top.  As you peer closer, you almost think "
        "you can see pictures in the stone's core.  Perhaps this is "
	"a scrying stone?"
    );
    set_weight(1);
    set_value(100);
    set_property("magic",1);
    set_type("ring");
    set_limbs( ({"left arm"}) );
    set_ac(0);
      set_wear("%^BLUE%^The %^YELLOW%^bracelet%^RESET%^%^BLUE%^ conforms to your wrist perfectly.");
      set_remove("%^BLUE%^You feel a pang of regret as the %^YELLOW%^bracelet%^RESET%^%^BLUE%^ slips from your wrist.");
}

void init() {
    ::init();
   if(!objectp(ETO)) return;
   if(!living(ETO)) return;
   if(!interactive(ETO)) return;
   ETO->force_me("wear opal bracelet");
    add_action("scry_func","scry");
}

string *dir_listing(string tempfil) {
    string *tmpstor, retval;
    tmpstor=explode(tempfil,"/");
    retval = "/"+implode(tmpstor - ({ tmpstor[sizeof(tmpstor) - 1] }),
        "/")+"/";   // removed .c here and added *.c below due to fix bugs *Styx* 9/27/03
    maindir = retval;
//   return get_dir(retval);  was this
    return get_dir(retval+"*.c");   // changed to this per teleport_without_error *Styx*
}

int scry_func(string str) {
   object ob,locale,*inv;
   string target, desc,*map_keys, real,*tempdir, file,failmsg;
   int i,matches;
   mapping map;

    if(!str) {
        notify_fail("Scry what?\n");
        return 0;
    }
//target = str;  this was apparently replaced with realName *Styx*  9/27/03
//    target = TP->realName(str);
//    if(!target || target == "") return notify_fail("You don't know a "+str+".\n");
//Begin code to use recognized names ~Circe~ 4/16/08
    target = lower_case(str);
    /*if(ETO->isKnown(target) || ((string)ETO->realName(target) != "") ) {
      map = (mapping)ETO->getRelationships();
      map_keys = keys(map);
      for(i=0;i<sizeof(map_keys);i++) {
         if (!stringp(map[map_keys[i]])) continue;
         if(lower_case(map[map_keys[i]]) == target) {
            matches++;
            real = lower_case(map_keys[i]);
         }
      }
     }
      if(!matches){
	   tell_object(ETO,"%^BOLD%^RED%^You do not recall a person called "+target+"!%^RESET%^");
	   return 1;
      }
      if(matches > 1) {
	   tell_object(ETO,"%^BOLD%^RED%^You know too many people with the same name!%^RESET%^");
	   return 1;
      }*/
      if((string)ETO->realName(target) != "") { real = lower_case((string)ETO->realName(target)); }
    else
    {
    tell_object(ETO,"%^BOLD%^RED%^You do not recall a person called "+target+"!%^RESET%^");
	    return 1;
    }
    ob = find_player(real);
//End code to use recognized names
    if( uses < 1 ||
       (int)TP->query_alignment() == 3 ||
       (int)TP->query_alignment() == 6 ||
       (int)TP->query_alignment() == 9) {
       write("%^BLUE%^As you concentrate on the %^WHITE%^Opal%^BLUE%^ "
	     "you realize that something is amiss.  The stone turns "
	     "%^CYAN%^clouded%^BLUE%^ and begins to shrink.  "
             "Soon the bracelet falls from your wrist and vanishes!"
       );
       TP->force_me("remove opal");
       TO->remove();
       return 1;   // didn't have this and got "Invalid message number!" but wasn't wearing it (too small) 
    }
    ob = find_living(target);  // moved this down here since it's not needed if it vapes
    uses--;
    failmsg = "%^BLUE%^You concentrate on the Opal but see only pretty "
              "%^CYAN%^c%^YELLOW%^o%^GREEN%^l%^MAGENTA%^o%^WHITE%^"
	      "u%^RED%^r%^BLUE%^s!\n";
    if(!ob || !objectp(ob)) {    // added objectp check *Styx*  9/27/03 last chg. 2/26/03
        write(failmsg);
//	notify_fail("");  Don't know why these would be needed *Styx* 9/27/03, changing all to use write and return 1 instead - return notify_fail doesn't translate the color codes
        return 0;
    }
    if(ob == TP) {
        write("%^BLUE%^As you peer into the opal, you see your reflection!");
 	return 1;
    }

// added check for true_invis for avatars here too *Styx* 9/27/03
    if(wizardp(ob) || ob->query_true_invis() || ob->query_property("no scry")) {
        write(failmsg);
	return 1;
    }
    locale = environment(ob);
    if (random(10) < 8) {
	tempdir = dir_listing(file_name(locale));
	if(sizeof(tempdir)) {
// changed this to check for sizeof to fix out of bounds errors *Styx*
//          if(sizeof(tempdir)) == 0 { file = base_name(environment(ob)); }
//          else { 
// if the array comes back empty, it will skip this and locale will stay set to original above
          file = maindir + tempdir[random(sizeof(tempdir))];
          locale = find_object_or_load(file);
//        } else {  // don't think this is even needed now *Styx*
//	  file = 0;   
//	  write(failmsg);
	}
    }
    if(!objectp(locale)) {
        write(failmsg);
	return 1;
    }
    desc = (string)locale->query_short()+"\n";
    inv = all_inventory(locale);
    for(i=0; i<sizeof(inv); i++) {
        if(inv[i]->query_invis()) continue;
        desc += (string)inv[i]->query_short()+"\n";
    }
    write("%^BLUE%^You concentrate on the %^WHITE%^opal%^BLUE%^ "
        "and see a scene take form.%^RESET%^"
        "\n"+desc+""
    );
    tell_room(ETP, TPQCN+" %^BLUE%^peers intently at an %^WHITE%^opal%^BLUE%^ bracelet."
    ,TP);
    // uses--;
    return 1;
}

/*  
int wearit() {
    FLAG = 1;
    tell_object(ETO,
        "%^BLUE%^The %^YELLOW%^Bracelet %^BLUE%^conforms to your wrist perfectly."
    );
    return 1;
}

int removeit() {
    FLAG = 0;
    tell_object(ETO,
    "%^BLUE%^You feel a pang of regret as the %^YELLOW%^bracelet%^BLUE%^ slips from your wrist."
    );
    return 1;
}
*/
