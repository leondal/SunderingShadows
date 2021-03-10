#include <std.h>
inherit MONSTER;
int DEATH = 0;
object blurgle;
int asked;

void create() {
    ::create();
    set_name("solar");
    set_id(({"solar", "Solar", "SOLAR"}));
   set_alignment(1);
    set_short("%^BOLD%^%^WHITE%^SOLAR%^RESET%^");
    set_long(
	"%^BOLD%^%^WHITE%^This incredible spirit stands boldly before you. " 
   "Its skin is the color of molten copper, its hair is bronze "
   "colored and its eyes appear to be two topaz gems inset into "
   "the eye sockets.  Massive muscles ripple across its body. "
	"It has a pair of angelic wings which are a coppery-gold color. "
	"The entire creature is bathed in a white glow indicating a holy "
 	"presence about it.  From legend, you have heard of this creature "
   "and know of its tremendous strength and god-like magical powers. "
	"Also from legend you know that attacking one is probably the "
	"stupidest thing you could ever do."
    );
    set_class("paladin");
    set_hd(30,7);
    set_overall_ac (-15);
    set_gender("male");
    set_race("spirit");
    set_guild_level("paladin",30);
    set_mlevel("paladin",30);
    set_hp(700);
    set_max_hp(700);
    set_mob_magic_resistance("average");
    set_property("full attacks", 1);
    set_exp(50000);
    set_size(3);
    set_body_type("human");
    set_wielding_limbs(({"right hand","left hand"}));
    set_stats("strength",30);
    set_stats("dexterity",30);
    set_stats("charisma",30);
    set_stats("constitution",30);
    set_stats("wisdom",30);
    set_stats("intelligence",30);
    set_attack_bonus(10);
    set_damage_bonus(10);
    set_emotes(3, ({
	"The %^BOLD%^%^WHITE%^SOLAR%^RESET%^ gazes into your soul.",
	"%^BOLD%^%^WHITE%^SOLAR says:  Are you noble enough to challenge "
      "the impending threat?%^RESET%^",
	"The light surrounding the %^WHITE%^%^BOLD%^SOLAR%^RESET%^ "
	"brightens and then dims.",
	"The %^WHITE%^%^BOLD%^SOLAR%^RESET%^ sizes you up."
      }),0);
    set_funcs(({"power"}));
    set_func_chance(50);
    new("/d/dagger/drow/obj/avenger.c")->move(TO);
    command("wield avenger in left hand");
}

void catch_say(string msg){
   call_out("sayfunc",1,msg,TP);
}

void sayfunc(string msg, object ob) {
    if(strsrch(msg, "yes") != -1) {
	message("environment",
	    "%^BOLD%^%^WHITE%^The SOLAR says:  %^YELLOW%^A threat to all "
	    "races of this world grows in the night.  A calling has been put "
	    "forth for the champions of all races to step forward and "
	    "destroy the growing threat.  I have been entrapped here to "
	    "speak of the %^MAGENTA%^quest%^YELLOW%^ to those who will "
	    "listen.", TP);
	return;
    }
    if(strsrch(msg, "quest") != -1) {
	message("environment",
	    "%^BOLD%^%^WHITE%^The SOLAR says:  %^YELLOW%^The "
	    "%^BLUE%^Drow%^YELLOW%^ have existed for many eons in this realm. "
	    "But now they have strengthened their power greatly. Within a city "
	    "of these evil beings awaits a %^RED%^temple%^YELLOW%^. Within "
	    "there grows an evil tool that they will soon use to conquer "
	    "this realm.",TP);
	return;
    }
    if(strsrch(msg, "drow") != -1) {
	message("environment",
	    "%^WHITE%^%^BOLD%^The SOLAR says:  %^YELLOW%^The "
	    "%^BLUE%^drow%^YELLOW%^ have constructed a "
	    "%^RED%^temple%^YELLOW%^ in which to conduct their worship of "
	    "the demonqueen %^BOLD%^%^BLACK%^Lloth%^YELLOW%^.",TP);
	return;
    }
    if(strsrch(msg, "city") != -1) {
	message("environment",
            "%^WHITE%^%^BOLD%^The SOLAR says:  %^YELLOW%^The %^BLUE%^Drow "
	    "%^YELLOW%^live in the city of Underdark.  Take great caution "
	    "there, and seek the hidden helper.",TP);
	return;
    }
    if(strsrch(msg, "temple") != -1) {
	message("environment",
	    "%^BOLD%^%^WHITE%^The SOLAR says:  %^YELLOW%^Within the "
	    "%^RED%^temple%^YELLOW%^ of the %^BLUE%^drow%^YELLOW%^ "
	    "lies a tool of great power. Through the efforts and worship "
	    "that the %^BLUE%^drow%^YELLOW%^ have performed they have "
	    "almost completed construction of the %^CYAN%^nodeus%^YELLOW%^. "
	    "With this lies the threat.",TP);
	return;
    }
    if(strsrch(msg, "loth") != -1) {
	message("environment",
	    "%^BOLD%^%^WHITE%^The SOLAR says:  %^YELLOW%^The evil Queen of "
	    "the spiders, known as %^BLACK%^Lloth%^YELLOW%^ resides in "
	    "her home dimension of the %^GREEN%^demonpits%^YELLOW%^. The "
	    "%^BLUE%^drow%^YELLOW%^ worship her and are constructing "
	    "the %^CYAN%^nodeus%^YELLOW%^ to allow her to enter this realm. "
	    "This is a grave danger to all mortal races of this realm. If "
	    "allowed to enter she will enslave every mortal within this "
	    "realm.",TP);
	return;
    }
    if(strsrch(msg, "nodeus") != -1) {
	message("environment",
	    "%^BOLD%^%^WHITE%^The SOLAR says, `%^YELLOW%^The "
	    "%^CYAN%^nodeus%^YELLOW%^ has two very important powers to "
	    "%^BLACK%^Lloth%^YELLOW%^ and the %^BLUE%^drow%^YELLOW%^. "
	    "First, it can be used by the high priests of the "
	    "%^BLUE%^drow%^YELLOW%^ to open the gate for "
	    "%^BLACK%^Lloth%^YELLOW%^ to enter your realm. "
	    "Second, it prevents my entrance to the "
	    "%^RED%^temple%^YELLOW%^ to destroy it. It is only I who can "
	    "completely erase the %^CYAN%^nodeus%^YELLOW%^.",TP);
	return;
    }
    if(strsrch(msg, "demonpit") != -1) {
	message("environment",
	    "%^BOLD%^%^WHITE%^The SOLAR says, `%^YELLOW%^The "
	    "%^GREEN%^demonpits%^YELLOW%^ is the name given to "
	    "%^BLACK%^Lloth's%^YELLOW%^ home plane. She will be able to "
	    "travel through the %^CYAN%^nodeus%^YELLOW%^ to this realm when "
	    "it is completed. The %^CYAN%^nodeus%^YELLOW%^ must be "
	    "deactivated so that i may enter the %^RED%^temple%^YELLOW%^ "
	    "and destroy it. Until such a time however, I am bound here "
	    "and its power continues to draw close to being "
	    "complete.",TP);
	return;
    }
    if(asked) return;
    if(!asked) {
       tell_room(ETO,"%^BOLD%^%^WHITE%^The Solar says:  %^YELLOW%^Have you "
          "come to help in our %^MAGENTA%^quest%^YELLOW%^ against Lloth's "
          "vile drow?");
       asked = 1;
       return;
    }
    return;
}

void heart_beat() {
    ::heart_beat();
    if(blurgle = present("snake")) {
            command("say I hate snakes!");
            message("environment", "%^WHITE%^SOLAR squashes the snake!"
                "%^RESET%^", ETO);
            blurgle->remove();
	    return;
    }
    return;
}

int power() {
   object ob = this_object();
   object vic = ob -> query_current_attacker();
   int move = random (2) + 1;
   switch (move) {
      case 1:
	message("environment",
	    "%^BOLD%^%^WHITE%^SOLAR says:  Think not mere mortal that I "
	    "will be defeated!  You are weak and foolish!",environment(ob));
	vic->set_paralyzed(random(100),
            "%^BOLD%^%^WHITE%^You are held by a holy force!%^RESET%^");
	    vic->do_damage("torso", random(20)+10);
	tell_room(environment(vic),
	    "%^WHITE%^%^BOLD%^The SOLAR touches "+vic->query_cap_name()+"'s "
	    "forehead and "+vic->query_cap_name()+
	    " is stunned by a holy force and unable to move!",({vic,ob}));
	tell_object(vic,
	    "%^WHITE%^%^BOLD%^The SOLAR touches your forehead and you "
	    "are stunned by a holy force!%^RESET%^");
	message("environment",
	    "%^BOLD%^%^YELLOW%^The %^WHITE%^SOLAR%^YELLOW%^ checks his "
	    "status and retreats to his home plane."
	    "\nAs he fades from view he mutters, "
	    "`%^WHITE%^Do not think i am done with you! "
	    "You will pay for your ignorance foolish mortal!"
	    "%^YELLOW%^'%^RESET%^",environment(ob));
	TO->move_player("/realms/grazzt/workroom", "with a blinding flash");
	message("environment",
	    "%^BOLD%^%^WHITE%^SOLAR chuckles."
	    "\nSOLAR says, `Just stopped in to heal up before trashing "
	    "some mortal who dared to attack me.'%^RESET%^",environment(ob));
	call_out("trans",30);
	return 1;

      case 2:
      if( DEATH < 2 ) {
	message("environment",
	    "%^WHITE%^%^BOLD%^The SOLAR traces the symbols of death in "
	    "the air!%^RESET%^",environment(ob));
	tell_object(vic,
	    "%^WHITE%^%^BOLD%^The SOLAR points the %^RED%^finger of "
	    "death%^WHITE%^ towards you!%^RESET%^");
	tell_room(environment(vic),
	    "%^WHITE%^%^BOLD%^The SOLAR points the %^RED%^finger of death "
	    "%^WHITE%^ at "+vic->query_cap_name()+"!%^RESET%^",vic);
	if("/daemon/saving_d"->saving_throw(vic,"spell")) {
	  message("environment",
	    "%^RED%^%^BOLD%^You feel the aura of death leave the "
	    "area.%^RESET%^", environment(ob));
	} else {
	message("environment",
	   "%^RED%^%^BOLD%^The aura of death seizes its foe and enforces "
	      "the death symbol!%^RESET%^", environment(ob));
	   vic->do_damage("torso",1000);
           DEATH = DEATH + 1;
	}
	return 1;
      } else {
      command("say GROWL! How dare you attack me!");
      return 1;
      }
   }
}

int trans() {
    object ob = this_object();
    TO->set_hp((int)TO->query_max_hp());
    message("environment",
	"%^BOLD%^%^WHITE%^The SOLAR says, `I am ready to fight again... the "
        "mortal will perish.'%^RESET%^"
	"\n%^YELLOW%^%^BOLD%^The %^WHITE%^SOLAR%^YELLOW%^ "
	"vanishes back to where it came from.%^RESET%^",environment(ob));
    TO->move_player("/d/dagger/drow/rooms/tun4", "with a blinding flash");
    message("environment",
	"%^BOLD%^%^WHITE%^The SOLAR says, "
	"`I have returned to end your life foolish mortal!'%^RESET%^"
        ,environment(ob));
}

void set_paralyzed(int time,string message){return 1;}
