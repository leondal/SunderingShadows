#include <std.h>
#include "../farm.h"
inherit WEAPONLESS;

#define BIRDS ({"chickadee","nightingale","skylark","blackbird","cardinal","wren"})

void create() {
object obj;
int i;
string BIRD,mycolor;
    	::create();
      i = random(sizeof(BIRDS));
      BIRD = BIRDS[i];
    	set_name("clockwork bird");
    	set_id(({"bird","songbird","clockwork bird","song bird","metallic bird",""+BIRD+"","farm_mon"}));
      set_short("a clockwork "+BIRD+"");
      switch(i){
         case 0: mycolor = "with a %^YELLOW%^yellow belly %^RESET%^"+
            "%^CYAN%^and %^BOLD%^%^BLACK%^blue-black head%^RESET%^"+
            "%^CYAN%^";
            break;
         case 1: mycolor = "from %^ORANGE%^brown plates "+
            "%^CYAN%^with "+
            "a %^RED%^red-sided tail%^CYAN%^";
            break;
         case 2: mycolor = "from %^YELLOW%^golden orange "+
            "%^RESET%^%^CYAN%^metal with %^ORANGE%^brown stripes%^CYAN%^";
            break;
         case 3: mycolor = "of %^BOLD%^%^BLACK%^black %^RESET%^"+
            "%^CYAN%^plates with spots of %^BOLD%^%^BLUE%^glinting blue"+
            "%^RESET%^%^CYAN%^";
            break;
         case 4: mycolor = "a beautiful %^BOLD%^%^RED%^red "+
            "%^RESET%^%^CYAN%^edged with %^BOLD%^%^BLACK%^black"+
            "%^RESET%^%^CYAN%^";
            break;
         case 5: mycolor = "with speckled %^ORANGE%^brown%^CYAN%^, "+
            "%^BOLD%^%^WHITE%^white%^RESET%^%^CYAN%^, and %^BOLD%^"+
            "%^BLACK%^black %^RESET%^%^CYAN%^metallic feathers";
            break;
         default: mycolor = "from tin";
            break;
      }
      set_long("This interesting little creature is a clockwork "+
         "creation!  It is made into the shape of a "+BIRD+" and "+
         "given matching characteristics.  The "+BIRD+" sings "+
         "continually as it moves about.  It has been crafted "+
         ""+mycolor+".  The bird is rather small and appears light, "+
         "made from thin metal plates almost like feathers.  A great "+
         "amount of time must have gone into its creation indeed.");
      set_gender("neuter");
      set_size(1);
    	set_hd(6,2);
    	set_class("fighter");
    	set_mlevel("fighter",6);
      set_race("clockwork bird");
      set_body_type("fowl");
    	set_stats("intelligence",6);
    	set_stats("wisdom",6);
    	set_stats("strength",15);  //yes, it's one strong bird :P
    	set_stats("charisma",16);
    	set_stats("dexterity",18);  //ninja bird!
    	set_stats("constitution",13);
	set("aggressive",7);
    	set_alignment(5);
    	set_overall_ac(5);
    	set_exp(200);
    	set_max_hp((random(10)+65));
    	set_hp(query_max_hp());
    	set_emotes(3,({
         "The "+BIRD+" trills out a song as it flits about.",
         "The "+BIRD+" preens its metallic feathers.",
         "The "+BIRD+" pecks at the ground, mimicking the search for insects.",
         "The "+BIRD+" raises its voice to sing to the winds."
    	}),0);
      set_attack_limbs(({"right claw","left claw","beak"}));
      set_damage(1,4);
      set_attacks_num(2);
    	set_max_level(9);
      set_property("swarm",1);
      add_money("gold",random(16)+50);
}