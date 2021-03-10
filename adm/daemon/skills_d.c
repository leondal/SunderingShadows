//      /adm/daemon/skills_d.c
//      from the Nightmare mudlib
//      contains code that would be very memory wasteful if in the user object
//      created by Descartes of Borg 14 february 1993
//  Added in the changes to spear and also parent weapons
//  of short and rapier - Cythera 8/05
#define BASE ({"mace","polearm","flail",\
"short blades","spear","rapier",\
"axe","hammer","club","knuckles",\
"staff","whip","fan"})
#define SIZED ({"blades"})

inherit "/std/daemon";

mapping init_skills(object ob) {
   mapping skills;
   string prof, cl, race;
// I really think this should have set skills = ([]) regardless.  I assume
//it doesn't because it was designed to allow setting youth weapons for
//someone later after it was implemented
   if(!skills) skills = ([]);
   race = ob->query_race();
   if(ob->is_class("cleric")) {
      cl = "cleric";
   }
   else if(ob->is_class("thief") || ob->is_class("assassin")) {
      cl = "thief";
   }
   else if(ob->is_class("bard") || ob->is_class("fighter")) {
      cl = "fighter";
   }
   else if(ob->is_class("paladin") || ob->is_class("antipaladin") ||
ob->is_class("cavalier")) {
      cl = "paladin";
   }
   else if(ob->is_class("ranger")) {
      cl = "ranger";
   }
   else if(ob->is_class("mage") || ob->is_class("psion"))
      cl = "mage";
// added to solve problem of a max already set to 120 for a parent and the
//parent taught getting reset to something else or a specialization already
//set *Styx* 9/24/05
   if(ob->query("youth weapon"))
        ob->set("max "+ob->query("youth weapon"), 100);
   if(ob->query("specialized"))
        ob->set("specialized", 0);
    if(!cl) {
      skills=([]);
   }
   else {
      switch(cl) {
      case "fighter":    /* change all this Kai!!!! */
         prof = (BASE+SIZED)[random(sizeof(BASE+SIZED))];
         if(member_array(prof,SIZED) != -1) {
            if((int)ob->query_size() == 1)
               prof = "small " +prof;
            if((int)ob->query_size() == 2)
               prof = "medium " +prof;
            if((int)ob->query_size() == 3)
               prof = "large " +prof;
         }
         skills[prof] = 100;
         ob->set("youth weapon",prof);
         ob->set("max "+prof,120);
         break;

      case "thief":
	    	switch(random(8)) {
                	case 0..1:
            skills["short blades"] = 100;
            ob->set("youth weapon","short blades");
                ob->set("max short blades",120);
                        break;
                   case 2..3:
                skills["small blades"] = 100;
                ob->set("youth weapon","small blades");
                ob->set("max small blades",120);
                        break;
                	case 4:
        skills["knuckles"] = 100;
         ob->set("youth weapon","knuckles");
         ob->set("max knuckles",120);
                        break;
                 case 5:
                skills["fan"] = 100;
                ob->set("youth weapon","fan");
                ob->set("max fan",120);
                        break;
			case 6..7:
                skills["rapier"] = 100;
                ob->set("youth weapon","rapier");
                ob->set("max rapier",120);
                break;
              }

           break;
      case "ranger":
         prof = SIZED[random(sizeof(SIZED))];
         if(race == "voadkyn") {
                switch(random(4)){
                       case 0..1:
            skills["large "+prof] = 100;
            ob->set("youth weapon","large "+prof);
                ob->set("max large "+prof,120);
                        break;
                        case 2..3:
                skills["spear"] = 100;
                ob->set("youth weapon","spear");
                ob->set("max spear",120);
                        break;
                	case 4..5:
                skills["axe"] = 100;
                ob->set("youth weapon","axe");
                ob->set("max axe",120);
                        break;
			case 6..7:
                skills["hammer"] = 100;
                ob->set("youth weapon","hammer");
                ob->set("max ",120);
                break;
                  }
         }
         else {
            switch(random(8)) {
                	case 0..1:
            skills["medium "+prof] = 100;
            ob->set("youth weapon","medium "+prof);
                ob->set("max medium "+prof,120);
                        break;
                   case 2..3:
                skills["spear"] = 100;
                ob->set("youth weapon","spear");
                ob->set("max spear",120);
                        break;
                	case 4..5:
                skills["axe"] = 100;
                ob->set("youth weapon","axe");
                ob->set("max axe",120);
                        break;
			case 6..7:
                skills["hammer"] = 100;
                ob->set("youth weapon","hammer");
                ob->set("max hammer",120);
                break;
              }
         }
         ob->set("specialized","long bow");
         skills["long bow"] = 50;
         break;

      case "paladin":
         skills["lance"] = 100;
         skills["medium blades"] = 100;
         ob->set("youth weapon","lance");

         ob->set("max lance",120);
         break;
      
	case "mage":
         if(!random(2)) {
            skills["staff"] = 100;
            ob->set("youth weapon","staff");

            ob->set("max staff",120);
         }
         else {
            skills["small blades"] = 100;
            ob->set("youth weapon","small blades");

            ob->set("max small blades",120);
         }
         break;
      
	case "cleric":
         switch(random(5)) {
         case 0:
            write("in the mace");
            skills["mace"] = 100;     
            ob->set("youth weapon","mace");
		ob->set("max mace",120);
            break;
         case 1:
            write("in the flail");
            skills["flail"] = 100;
            ob->set("youth weapon","flail");
		ob->set("max flail",120);
            break;
         case 2:
            write("in the staff");
            skills["staff"]=100;
            ob->set("youth weapon","staff");
		ob->set("max staff",120);
            break;
         case 3:
            write("in the hammer");
            skills["hammer"] = 100;
            ob->set("youth weapon","hammer");
            ob->set("max hammer",120);
            break;
         case 4:
            write("in the club");
            skills["club"] = 100;
            ob->set("youth weapon","club");
            ob->set("max club",120);
            break;

         }
      }
   }
   return skills;
}

int training_formula(object player, string skill) {
   string youth, classes;
   int profs, level, total, percent,close,i,j;
   int max;

   percent = player->query_skill(skill);
   youth = player->query("youth weapon");
   level = player->query_lowest_level();
   switch (level) {
    case 1..10: break;
    case 11..30: level = 10 + (level-10)/2; break;
    case 31..60: level = 20 + ((level - 20) / 3); break;
   default: level = level / 4;
  }
   close = player->query(skill);
   profs = player->query_profs(skill);
   max = player->query("max "+skill);

   if (!max) {
      max = 100;
   }
   if(profs < 1 && percent > 49) return 0;
   if(profs < 2 && percent > 74) return 0;
   

   if (percent >= max) {
      return 0;
   }

   if(close >= percent) {
      player->increase_skill(skill,1);
      player->set(skill,0);
      return 1;
   }

   // tweaked a little more, to speed it up -Ares 6/03/08
   close= close+level+8+((random(12)+3)*6);
   //close= close+level+8+(random(12)*6);  /// changed from
///close=close+level+random(50) due to monster heart beat slow down - garrett
///02/22/2007
   player->set(skill,close);
   return 1;

}
