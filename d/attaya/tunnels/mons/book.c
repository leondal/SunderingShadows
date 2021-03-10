//Coded by Lujke, with code plundered from Cythera and Styx
#include <std.h>
#include "../tunnel.h"
inherit WEAPONLESS;

#define COLOURS ({"%^BOLD%^%^BLACK%^pitch black",\
"%^RESET%^%^RED%^blood red",\
"%^RESET%^%^ORANGE%^sunset orange",\
"%^RESET%^%^ORANGE%^walnut brown",\
"%^RESET%^%^BLUE%^midnight blue",\
"%^BOLD%^%^BLACK%^raven black",\
"%^BOLD%^%^CYAN%^sky blue",\
"%^ORANGE%^brown"})

#define TYPES ({"book","tome","volume","codex","compendium","folio","lexicon","treatise","text","monograph"})

#define MATERIALS ({"leather","skin","velvet","leather","vellum"})

void die(mixed ob);

void create()
{
  int i,x,y;
  string type, colour, material;
  i = random(sizeof(COLOURS));
  colour = COLOURS[i];
  x = random(sizeof(TYPES));
  type = TYPES[x];
  y = random(sizeof(MATERIALS));
  material = MATERIALS[y];
  ::create();
  set_name(type);

  switch(type)
  {
  case "book":
    set_long("%^RESET%^A large, hard backed book, bound in "
            + colour + " " + material + "%^RESET%^. It seems to be"
            +" animated by some %^RED%^m%^BOLD%^%^RED%^a%^RESET%^"
            +"%^RED%^levol%^BOLD%^%^BLACK%^a%^RESET%^%^RED%^nt"
            +"%^RESET%^ force and its covers flap menacingly as"
            +" it weaves its way through the air, pages fluttering"
            +" in the breeze.\n");
    set_short("%^RESET%^"+colour+" " + material + " hard backed"
             +" book%^RESET%^");
    set_id(({"book","hardback book", "hard backed book"}));
    break;
  case "tome":
    set_long("%^RESET%^A weighty tome, clearly filled with"
            +" %^GREEN%^a%^BOLD%^%^GREEN%^r%^RESET%^%^GREEN%^ca"
            +"%^BOLD%^%^GREEN%^ne%^RESET%^ knowledge,"
            +" pressed between its " + colour + " " + material
            +" %^RESET%^covers. It has been animated by a force of"
            +" %^MAGENTA%^magic%^RESET%^, or perhaps by the"
            +" %^CYAN%^enchantment%^RESET%^ contained within, and"
            +" is now rising up to attack!\n");
    set_short("%^RESET%^"+colour+" "+ material+ " covered tome%^RESET%^");
    set_id(({"tome","book","weighty tome"}));
    break;
  case "volume":
    set_long("%^RESET%^A "+colour+" volume%^RESET%^, with pages sewn"
            +" carefully between its " + material + " covers. It"
            +" seems to have been animated and is flying through"
            +" the air ready to attack!\n");
    set_short("%^RESET%^"+colour+" volume backed in " + material
            + "%^RESET%^");
    set_id(({"book","volume",material + " covered volume",colour
                                                    + " volume"}));
    break;
case "monograph":
    set_long("%^RESET%^A slim volume set between " + colour + " "
            + material + "%^RESET%^ covers, with a text on a single"
           + " subject. With the %^MAGENTA%^magic%^RESET%^ now"
           + " embuing it, it seems to be just as single-minded"
           + " about killing anyone it can!\n");
    set_short("%^RESET%^"+colour+" " + material
             +" %^RESET%^covered monograph");
    set_id(({"monograph","book",colour + " monograph",
                                                   colour + "book"}));
    break;
  default:
    set_long("%^RESET%^A " + type + " covered with a binding of "
            + colour + " " + material + "%^RESET%^. The subject"
            +" matter is undoubtedly %^GREEN%^a%^BOLD%^%^GREEN%^r"
            +"%^RESET%^%^GREEN%^ca%^BOLD%^%^GREEN%^n%^RESET%^"
            +"%^GREEN%^e%^RESET%^ in nature, and the " + type
            +" appears to have been seized with magic itself, as it"
            +" is flying around in the air attacking whatever it can"
            +" reach!\n");
    set_short("%^RESET%^"+colour+" "+ material +"%^RESET%^ covered "
               + type+"%^RESET%^");
    set_id(({type,"book", colour+" "+type, colour + " book"}));
    break;
  }

   set_gender("neuter");
   set_race("book");
   set_body_type("snake");
   remove_limb("head");
   remove_limb("mouth");
   remove_limb("tail");
   set_attack_limbs(({"torso"}));
   set_size(1);
   set_alignment(5);
   set_overall_ac(-4);
   set_hd(15,6);
   set_level(15);
   set_class("fighter");
   set_mlevel("fighter",15);
   set("aggressive",25);
   set_class("fighter");
   set_mlevel("fighter",20);
   set_level(20);
   set_hp(random(100)+50);
//	set_speed(30);
   set_exp(1000);
   set_max_level(50);
   set_property("swarm",1);
   set_overall_ac(-1);
   set_mob_magic_resistance("extremely high");
   set_property("full attacks",1);
   set_emotes(10,({
		query_short() + " flaps its covers menacingly as it flies"
            +" round the room",
            query_short()+ " emits a %^BOLD%^%^CYAN%^shrill"
            +" %^RESET%^screech and rejoins the attack!",
            query_short() + " flaps into your face!",
            query_short() + " loses a page, which disintegrates as it"
            +" falls to the floor",
            query_short() + " drops to the floor for a moment, then"
            +" takes off again",
            query_short() + " takes shelter on a shelf",
            query_short() + " takes roost on the ceiling",
            query_short() + " swoops down from above!"
   }),1);
}




void die(mixed ob) {
    int num_pages;
    object page;
    num_pages = 0;
   switch(random(20)) {// yes it's intentional to not have breaks.. *Styx*
	case 0..12:  break;
 	case 13..14:
        page= new(OBJ + "page");
        if (!objectp(page)) { tell_room(ETO, "page failed to load");break;}
        page->move(TO);
        num_pages++;
    case 15..16:
    case 17..18:
        page= new(OBJ + "page");
        if (!objectp(page)) {tell_room(ETO, "page failed to load");break; }
        page->move(TO);
        num_pages++;
	case 19:
        page= new(OBJ + "page");
        if (!objectp(page)) {tell_room(ETO, "page failed to load");break; }
        page->move(TO);
        num_pages++;
        break;
   }
   if(num_pages)
   {
     tell_room(ETO, "As the " + query_name()+ " %^RESET%^falls apart, a"
                   +" page or two of writing flutters forlornly down"
                   +" to the floor");
   }
   ::die(ob);
}
