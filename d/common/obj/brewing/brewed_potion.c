// inherit for brewed potions, self-affecting only. N, 11/11.
// for duration-based potions, ensure to use temporary status bonuses only, as there is no cancel-on-quit which would leave permanent bonuses.
#include "./brew.h"
inherit BREWINH;

#define STATE ({"dark","pale","light","roiling","bubbling","murky","shadowed","dull","misty","opaque","smoky"})
#define RED ({"red","scarlet","crimson","blood-red","rusty","rose","carmine","garnet","ruby","vermilion"})
#define YELLOW ({"yellow","amber","golden","ochre","citrine","tawny","lemon","straw-hued"})
#define GREEN ({"green","viridian","emerald","jade","moss-green","malachite","olive","chartreuse","beryl"})
#define BLUE ({"azure","cyan","blue","sapphire","aquamarine","violet","cerulean","indigo","teal","turquoise","cobalt"})

string myvar;

void create() {
    ::create();
    set_id(({ "potion","vial" }));
    set_short("A crystalline vial");
    set_long("This smooth crystal vial is rather small and tear-drop shaped. It is completely clear, allowing you to see "
"the potion that swirls inside.");
    set_lore("%^RESET%^This potion is one crafted by many alchemists of the land.  Because of the ingredients used, "
"such potions often have similar qualities, such as color and smell.");
    set_property("lore difficulty",1);
    set_value(1);
    set_weight(1);
    switch(random(10)) {
      case 0: attribute = "aroma"; break;
      case 1: attribute = "scent"; break;
      case 2: attribute = "hue"; break;
      case 3: attribute = "shade"; break;
      case 4: attribute = "viscosity"; break;
      case 5: attribute = "opacity"; break;
      case 6: attribute = "density"; break;
      case 7: attribute = "consistency"; break;
      case 8: attribute = "smoothness"; break;
      case 9: attribute = "composition"; break;
    }
}

void init() {
    ::init();
    add_action("drink_potion","drink");
    add_action("drink_potion","quaff");
}

int drink_potion(string str) {
   if(!objectp(TP)) return 0;
   if(TP != ETO) return 0;
   if(TP->query_bound() || TP->query_unconscious()) {
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(TP->query_paralyzed()) return notify_fail(TP->query_paralyze_message()+"\n");
   if(TP->query_property("potion effect") && !TO->query_property("instant potion")) {
     tell_object(TP,"%^BOLD%^%^WHITE%^You throw back the potion, but it has no effect against the one you've already consumed.%^RESET%^");
     TO->remove();
     return 1;
   }

   tell_object(TP,"%^BOLD%^%^WHITE%^You quickly quaff the draught from the potion.%^RESET%^\n");
   tell_room(ETP,TP->QCN+" drinks from a small vial.\n",TP);
   TP->set_property("potion effect",myname);
   if(myvar) {
     if(reversed) "/daemon/delay_d"->sleep(base_name(TO),"potion_backfire",random(5)+7,({ TP, strength, myvar }));
     else "/daemon/delay_d"->sleep(base_name(TO),"potion_effect",random(5)+7,({ TP, strength, myvar }));
   }
   else {
     if(reversed) "/daemon/delay_d"->sleep(base_name(TO),"potion_backfire",random(5)+7,({ TP, strength }));
     else "/daemon/delay_d"->sleep(base_name(TO),"potion_effect",random(5)+7,({ TP, strength }));
   }
   TO->remove();
   return 1;
}

// please over-write these function for potion effect and backfire.
// potion_ending function is not required unless non-spell duration-based effect is desired.
int potion_effect(object drinker,int strength,string str) {
    if(!objectp(drinker)) return 0;
    return 1;
}

int potion_backfire(object drinker,int strength,string str) {
    if(!objectp(drinker)) return 0;
    return 1;
}

// please over-write these function for ending duration-based effects.
// File MUST be invoked directly; call-out to the same object will fail as the object will be gone.
int potion_ending(object drinker,int strength,string str) {
    if(!objectp(drinker)) return 0;
    return 1;
}

int potion_backfire_ending(object drinker,int strength,string str) {
    if(!objectp(drinker)) return 0;
    return 1;
}

void set_hue(string myhue) {
    string mystate, myshade, mycolorcode;

    mystate = STATE[random(sizeof(STATE))];
    switch(myhue) {
      case "blue":
        myshade = BLUE[random(sizeof(BLUE))];
        switch(random(3)) {
          case 0: mycolorcode = "%^RESET%^%^BLUE%^"; break;
          case 1: mycolorcode = "%^BOLD%^%^BLUE%^"; break;
          default: mycolorcode = "%^BOLD%^%^CYAN%^"; break;
        }
      break;
      case "red":
        myshade = RED[random(sizeof(RED))];
        switch(random(3)) {
          case 0: mycolorcode = "%^RESET%^%^RED%^"; break;
          case 1: mycolorcode = "%^BOLD%^%^RED%^"; break;
          default: mycolorcode = "%^BOLD%^%^MAGENTA%^"; break;
        }
      break;
      case "green":
        myshade = GREEN[random(sizeof(GREEN))];
        switch(random(3)) {
          case 0: mycolorcode = "%^RESET%^%^GREEN%^"; break;
          case 1: mycolorcode = "%^BOLD%^%^GREEN%^"; break;
          default: mycolorcode = "%^RESET%^%^CYAN%^"; break;
        }
      break;
      case "yellow":
        myshade = YELLOW[random(sizeof(YELLOW))];
        switch(random(2)) {
          case 0: mycolorcode = "%^RESET%^%^ORANGE%^"; break;
          default: mycolorcode = "%^YELLOW%^"; break;
        }
      break;
      default: mycolorcode = "%^RESET%^"; break;
    }
    set_id(({ "potion", "vial", mystate+" potion", myshade+" potion", mystate+" "+myshade+" potion" }));
    set_obvious_short("%^BOLD%^%^WHITE%^a vial containing a "+mycolorcode+mystate+" "+myshade+
"%^BOLD%^%^WHITE%^ potion%^RESET%^");
    set_short(""+mycolorcode+myname+"%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^This smooth %^BOLD%^%^CYAN%^crystal vial %^BOLD%^%^WHITE%^is rather small and tear-drop "
"shaped. It is completely %^RESET%^%^WHITE%^clear%^BOLD%^%^WHITE%^, allowing you to see a "+mycolorcode+mystate+
" "+myshade+" potion %^BOLD%^%^WHITE%^that swirls inside.%^RESET%^");
}

void set_myvar(string str) { myvar = str; }
string query_myvar() { return myvar; }