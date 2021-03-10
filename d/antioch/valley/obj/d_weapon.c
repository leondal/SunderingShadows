//Updated with weapon feats - Octothorpe 12/16/09

#include <std.h>
#include "../valley.h"

#define NAMES ({ "%^BOLD%^%^WHITE%^s%^RESET%^i%^BOLD%^l%^RESET%^v%^BOLD%^e%^RESET%^r",\
"%^BOLD%^%^WHITE%^m%^CYAN%^i%^WHITE%^thr%^CYAN%^i%^WHITE%^l%^RESET%^",\
"%^RESET%^%^ORANGE%^br%^YELLOW%^o%^RESET%^%^ORANGE%^n%^BOLD%^z%^RESET%^%^ORANGE%^e%^RESET%^",\
"%^BOLD%^%^BLACK%^obsidian%^RESET%^",\
"%^RESET%^%^CYAN%^s%^BOLD%^t%^RESET%^%^CYAN%^e%^BOLD%^e%^RESET%^%^CYAN%^l%^RESET%^",\
"%^YELLOW%^mabion%^RESET%^",\
"%^BOLD%^%^WHITE%^cry%^CYAN%^s%^WHITE%^tal%^RESET%^",\
"%^RESET%^s%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^o%^RESET%^n%^BOLD%^%^BLACK%^e%^RESET%^",\
"%^BOLD%^%^BLACK%^i%^RESET%^%^BLUE%^r%^BOLD%^%^BLACK%^%^o%^RESET%^%^BLUE%^n%^RESET%^",\
"%^BOLD%^%^BLACK%^adamantium%^RESET%^",\
"%^BOLD%^%^WHITE%^titanium%^RESET%^",\
"%^BOLD%^%^WHITE%^diamond%^RESET%^",\
"%^BOLD%^%^RED%^r%^RESET%^%^RED%^u%^BOLD%^%^RED%^b%^RESET%^%^RED%^y%^RESET%^",\
"%^BOLD%^%^WHITE%^iv%^YELLOW%^o%^WHITE%^ry%^RESET%^",\
"%^BOLD%^%^BLUE%^s%^CYAN%^a%^RESET%^%^CYAN%^p%^BLUE%^p%^BOLD%^h%^CYAN%^i%^RESET%^%^CYAN%^r%^BLUE%^e%^RESET%^",\
"%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^m%^BOLD%^e%^RESET%^%^GREEN%^r%^BOLD%^a%^RESET%^%^GREEN%^l%^BOLD%^d%^RESET%^",\
"%^YELLOW%^g%^RESET%^%^ORANGE%^o%^BOLD%^l%^RESET%^%^ORANGE%^d%^RESET%^"})

inherit DAEMON;

int i, j, val, x;
string str, TYPE, SIZE, style;

void create()
{
	::create();
}

void create_weapon(object obj)
{
	j = random(sizeof(NAMES));
	style = NAMES[j];
	val = random(1800);
	switch(val) {
		case 0..99:
			TYPE = "knife";
			obj->set_wc(1,3);
			obj->set_large_wc(1,2);
            obj->set_type("piercing");
			obj->set_prof_type("small blades");
            obj->set_weapon_prof("simple");
			obj->set_weight(2);
			break;
		case 100..199:
			TYPE = "dagger";
			obj->set_wc(1,4);
			obj->set_large_wc(1,3);
			obj->set_type("piercing");
            obj->set_prof_type("small blades");
			obj->set_weight(2);
			break;
		case 200..299:
			TYPE = "club";
			obj->set_wc(1,6);
			obj->set_large_wc(1,3);
         	obj->set_type("bludgeoning");
            obj->set_weapon_prof("simple");
            obj->set_prof_type("club");
			obj->set_weight(5);
			break;
		case 300..399:
			TYPE = "staff";
			obj->set_wc(1,6);
			obj->set_large_wc(1,6);
            obj->set_type("bludgeoning");
			obj->set_prof_type("staff");
            obj->set_weapon_prof("simple");
			obj->set_weight(5);
			break;
		case 400..499:
			TYPE = "lance";
			obj->set_wc(1,8);
			obj->set_large_wc(2,8);
			obj->set_type("pierce");
			obj->set_property("lance",1);
			obj->set_prof_type("lance");
			obj->set_weapon_prof("martial");
            obj->set_weight(7);
            obj->set_hit((:TO,"checkme":));
			break;
		case 500..599:
			TYPE = "morning star";
			obj->set_wc(2,4);
			obj->set_large_wc(1,6);
			obj->set_type("bludgeoning");
            obj->set_prof_type("mace");
            obj->set_weapon_prof("simple");
			obj->set_weight(7);
			break;
		case 600..699:
			TYPE = "pick";
			obj->set_wc(1,6);
			obj->set_large_wc(2,4);
			obj->set_type("pierce");
            obj->set_prof_type("short blades");
            obj->set_weapon_prof("martial");
			obj->set_weight(7);
			break;
		case 700..799:
			TYPE = "sickle";
			obj->set_wc(1,6);
			obj->set_large_wc(1,4);
			obj->set_type("slashing");
            obj->set_prof_type("small blades");
            obj->set_weapon_prof("simple");
			obj->set_weight(4);
			break;
		case 800..899:
			TYPE = "trident";
			obj->set_wc(1,6);
			obj->set_large_wc(3,4);
			obj->set_type("pierce");
            obj->set_prof_type("spear");
            obj->set_weapon_prof("martial");
			obj->set_weight(8);
			break;
		case 900..999:
			TYPE = "scimitar";
			obj->set_wc(1,8);
			obj->set_large_wc(1,8);
			obj->set_type("slashing");
			obj->set_profs("medium blades");
            obj->set_weapon_prof("martial");
			obj->set_weight(7);
			break;
		case 1000..1099:
			TYPE = "whip";
			obj->set_wc(1,6);
			obj->set_large_wc(1,6);
            obj->set_type("lash");
         	obj->set_prof_type("whip");
            obj->set_weapon_prof("exotic");
			obj->set_weight(3);
 			break;
		case 1100..1199:
			TYPE = "flail";
			obj->set_wc(1,6);
			obj->set_large_wc(2,4);
			obj->set_type("bludgeoning");
         	obj->set_prof_type("flail");
			obj->set_weapon_prof("martial");
            obj->set_weight(7);
			break;
		case 1200..1299:
			TYPE = "mace";
			obj->set_wc(1,8);
			obj->set_large_wc(1,6);
			obj->set_type("bludgeoning");
            obj->set_prof_type("mace");
            obj->set_weapon_prof("simple");
			obj->set_weight(7);
			break;
		case 1300..1399:
			TYPE = "halberd";
			obj->set_wc(1,10);
			obj->set_large_wc(2,6);
			obj->set_type("pierce");
			obj->set_prof_type("polearm");
            obj->set_weapon_prof("martial");
			obj->set_weight(9);
			break;
		case 1400..1499:
			TYPE = "spear";
			obj->set_wc(1,6);
			obj->set_large_wc(1,8);
			obj->set_type("pierce");
			obj->set_prof_type("spear");
			obj->set_weight(5);
			break;
		case 1500..1599:
			TYPE = "hammer";
			obj->set_wc(1,6);
			obj->set_large_wc(2,4);
			obj->set_type("bludgeoning");
            obj->set_prof_type("hammer");
            obj->set_weapon_prof("martial");
			obj->set_weight(7);
			break;
		case 1600..1699:
			TYPE = "axe";
			obj->set_wc(1,8);
			obj->set_large_wc(1,8);
			obj->set_type("slash");
            obj->set_prof_type("axe");
            obj->set_weapon_prof("martial");
			obj->set_weight(7);
			break;
		case 1700..1799:
			TYPE = "sword";
			obj->set_wc(2,4);
			obj->set_large_wc(1,6);
			obj->set_type("slashing");
			obj->set_weight(7);
			break;
	}
	switch(random(4)) {
		case 0:
			SIZE = "small";
			obj->set_size(1);
				if(TYPE == "spear") {
					obj->set_prof_type("small spear");
				    obj->set_weapon_prof("simple");
				}
				if(TYPE == "dagger") {
					obj->set_prof_type("small blades");
				    obj->set_weapon_prof("simple");
				}
				if(TYPE == "sword") {
					obj->set_prof_type("short blades");
				    obj->set_weapon_prof("martial");
				}
				if(style == "mabion") {
					obj->set_weapon_speed(1);
				}
            if(TYPE == "lance") {
               obj->set_size(2);
					obj->set_weapon_speed(8);
            }
			break;
		case 1:
			SIZE = "medium";
			obj->set_size(2);
				if(TYPE == "spear") {
					obj->set_prof_type("medium spear");
				    obj->set_weapon_prof("simple");
				}
				if(TYPE == "dagger") {
					obj->set_prof_type("small blades");
				    obj->set_weapon_prof("simple");
				}
				if(TYPE == "sword") {
					obj->set_prof_type("medium blades");
				    obj->set_weapon_prof("martial");
				}
				if(style == "mabion") {
					obj->set_weapon_speed(3);
				}
			break;
		case 2:
			SIZE = "large";
			obj->set_size(3);
				if(TYPE == "spear") {
					obj->set_prof_type("large spear");
				    obj->set_weapon_prof("simple");
				}
				if(TYPE == "dagger") {
					obj->set_prof_type("large blades");
				    obj->set_weapon_prof("exotic");
				}
				if(TYPE == "sword") {
					obj->set_prof_type("large blades");
					obj->set_weapon_prof("exotic");
				}
				if(TYPE == "hammer") {
                    obj->set_prof_type("hammer");
					obj->set_weapon_prof("martial");
				}
				if(TYPE == "axe") {
                  obj->set_prof_type("axe");
				    obj->set_weapon_prof("martial");
				}
				if(style == "mabion") {
					obj->set_weapon_speed(7);
				}
            if(TYPE == "lance") {
               obj->set_size(2);
					obj->set_weapon_speed(8);
            }
			break;
		case 3:
			SIZE = "huge";
			obj->set_size(4);
				if(TYPE == "spear") {
					obj->set_prof_type("large spear");
					obj->set_weapon_prof("exotic");
				}
				if(TYPE == "dagger") {
					obj->set_prof_type("large blades");
					obj->set_weapon_prof("exotic");
				}
				if(TYPE == "sword") {
					obj->set_prof_type("large blades");
					obj->set_weapon_prof("exotic");
				}
				if(TYPE == "hammer") {
                   obj->set_prof_type("giant hammer");
				   obj->set_weapon_prof("exotic");
				}
				if(TYPE == "axe") {
                   obj->set_prof_type("giant axe");
				   obj->set_weapon_prof("exotic");
				}
				if(style == "mabion") {
					obj->set_weapon_speed(9);
				}
            if(TYPE == "lance") {
               obj->set_size(2);
					obj->set_weapon_speed(8);
            }
			break;
	}

	obj->set_name(TYPE);
	obj->set_id(({"weapon",TYPE,""+style+" "+TYPE+"",""+SIZE+" "+TYPE+"", ""+SIZE+" "+style+" "+TYPE+""}));
	obj->set_short("A "+SIZE+" "+style+" "+TYPE+"");
	obj->set_long(
	"%^RESET%^This is a %^BOLD%^"+SIZE+" %^BOLD%^%^BLACK%^"+TYPE+" %^RESET%^. It is made out of "+style+""+
	" and looks to be in very good shape. In the right hands,"+
	" this is a fine weapon."
	);
	if(TYPE == "whip") {
		obj->set_long("%^RESET%^This is a %^BOLD%^"+SIZE+" %^RESET%^whip. It is made out of"+
		" strips of hardened leather. The handle is woven with"+
		" "+style+" to make it stronger.");
	}
   switch(j) {
      case 0..1:
         x = random(400)+200;
         break;
      case 2..4:
         x = random(200)+50;
         break;
      case 5..6:
         x = random(500)+275;
         break;
      case 7..8:
         x = random(200)+75;
         break;
      case 9..11:
         x = random(600)+325;
         break;
   }
   obj->set_value(x);
   obj->set_property("enchantment",(random(2))+2);
       obj->set_lore("Omrick Greenwood was a skilled blacksmith in "+
                "service to the faith of Law.  Omrick strived to bring "+
                "the message of Law to all in the lands, by crafting and"+
                " enchanting weapons.  These weapons helped many temples, "+
                "kingdoms and city-states arm their forces in the event of "+
                "war.  Through Omrick's service to the church of Law, he"+
                " was blessed with a special honor.  Now among the faith of"+
                " The Lord of Battles the favored blacksmith is given the "+
                "title Omrick.");
        obj->set_property("lore difficulty",5);
  }
