//updated by Circe 6/1/04 with new desc, lore, etc, by Shar
#include <std.h>
#include "/d/shadow/room/goblin/short.h"

inherit "/d/common/obj/weapon/longsword";
int uses,xx,yy,FLAG;
void create() {
    ::create();
    set_name("sword");
    set_id(({"sword","longsword","sword of insanity","insanity"}));
    set_short("%^BOLD%^%^MAGENTA%^Sword of Insanity%^RESET%^");
    set_long(
"It is hard to determine what kind of metal this curious blade is made out of.  As you see the entire blade has been painting with %^YELLOW%^c%^CYAN%^h%^GREEN%^a%^BLACK%^o%^BLUE%^t%^RED%^i%^MAGENTA%^c%^RESET%^ stripes in a dazzling variety of colors.  There is no rhyme or reason to the stripes it seems, their size and colors vary at whim.  Some start out wide and taper off to skinny, while others use at least seven different colors just to finish one stripe.  The pommel of this long sword is wrapped with strips of %^CYAN%^basket-woven %^RESET%^cotton, giving plenty of cushions for the hands, and adding to the motley array of colors."
        );
    set_lore("The Sword of Insanity is an ancient sword from Shadow's "+
       "past.  The sword in truth was made somewhere in the second or "+
       "third century and was deemed a holy blade to the deity of Good "+
       "Fortune then, Tymora.  Sages believe that this is indeed the "+
       "same Tymora that has made a return to the lands in recent years."+
       "  The blade was a favored weapon for all of Tymora's followers, "+
       "for it offered a comical appeal in the middle of battle and "+
       "just when the Tymorian needed a bit of good luck it seemed to "+
       "come to them.  Though more rigid and serious folks called the "+
       "sword insane and said only an insane man would trust in it in "+
       "battle.  Thus its name was born.  For Good Fortune favors the "+
       "foolish sometimes, they say.");
    set_property("lore difficulty",9);
    set_value(100);
    set_hit((: TO, "extra_hit":));
    set_wield((: TO, "extra_wield":));
    set_unwield((: TO, "extra_unwield" :));
    set_property("enchantment",1);
    set_heart_beat(1);
    uses = random(75)+50;
}
void heart_beat() {
    int align,i;
    object owner,env,obj,*inv;
    env = ETO;
    if(!objectp(ETO)) return;
    if(objectp(env) && living(env)) {
        owner = env;
        env = environment(owner);
    }
    if(!(TO->query_wielded())) {
        return;
    } else {
        if( obj = present("corpse",env)) {
            tell_object(owner,"%^MAGENTA%^%^BOLD%^"
                "The sword giggles in an insane manner and the corpse\n"
	        "before you stands up and performs a strange dance as\n"
	        "it slowly fades from view!"
                "%^RESET%^"
            );
            owner->heal(random(2)+2);
	    uses = uses + random(2)+1;
            obj->remove();
            return;
        } else {
            xx = random(500);
            yy = random(19)+1;
            if(xx < 1) {
                if(yy == 1) {
                    tell_object(owner,"%^RED%^%^BOLD%^"
                        "The sword tells you: %^RESET%^"
                        "DOH! What was I thinking? Hehehe..."
                    );
                }
                if(yy == 2) {
                    tell_object(owner,"%^RED%^%^BOLD%^"
                        "The sword tells you: %^RESET%^"
                        "Are we killing or what?!?"
                    );
                }
                if(yy == 3) {
                    tell_object(owner,"%^RED%^%^BOLD%^"
                        "The sword tells you: %^RESET%^"
                        "Grrr...*grumble*...what the hell..."
                    );
                }
                if(yy == 4) {
                    tell_object(owner,"%^RED%^%^BOLD%^"
                        "The sword tells you: %^RESET%^"
                        "Uhhh...not that it matters but...How wise "
                        "are you again?"
                    );
                }
                if(yy == 5) {
                    tell_object(owner,"%^RED%^%^BOLD%^"
                        "The sword tells you: %^RESET%^"
                        "Hmm...thats really strange...umm...well nevermind, "
		        "I doubt it will affect combat anyways."
                    );
                }
                if(yy == 6) {
                    tell_object(owner,"%^RED%^%^BOLD%^"
                        "The sword tells you: %^RESET%^"
                        "The best things to kill are wizards. I *REALLY* "
                        "hate wizards!"
                    );
                }
                if(yy == 7) {
                    tell_object(owner,"%^RED%^%^BOLD%^"
                        "The sword tells you: %^RESET%^"
                        "By the way...Are you planning on pulling your weight? "
                        "Seems during combat I do all the work!"
                    );
                }
                if(yy == 8) {
                    tell_object(owner,"%^RED%^%^BOLD%^"
                        "The sword tells you: %^RESET%^"
                        "WHOA...Did you see that or am I having those "
                        "wicked delusions again???"
                    );
                }
if(yy == 11) tell_object(owner,"%^RED%^%^BOLD%^The sword tells you: %^RESET%^We land a blow almost as much as a goblin bathes!");
if(yy == 12) tell_object(owner,"%^RED%^%^BOLD%^The sword tells you: %^RESET%^Someday we will slay the evil in Demongate tower...wait a sec...who am I kidding!");
if(yy == 13) tell_object(owner,"%^RED%^%^BOLD%^The sword tells you: %^RESET%^I think your armor is decaying!!!");
if(yy == 14) tell_object(owner,"%^RESET%^Some gold falls out of your pocket!");
if(yy == 15) tell_object(owner,"%^RESET%^You meow.");
if(yy == 16) tell_object(owner,"%^RESET%^You are getting sleepy.");
if(yy == 17) tell_object(owner,"%^RED%^%^BOLD%^The sword tells you: %^RESET%^Why do we fight all this weenie stuff? What's wrong with dragons and such?!");
if(yy == 18) tell_object(owner,"%^RED%^%^BOLD%^The sword tells you: %^RESET%^And for my next trick I will wield you in both hands!");
if(yy == 19) tell_object(owner,"%^RED%^%^BOLD%^The sword tells you: %^RESET%^SHUSH!!! Did you hear that?!? Game over man...GAME OVER!!!");
                if(yy == 9) {
                    tell_object(owner,"%^RED%^%^BOLD%^"
                        "The sword tells you: %^RESET%^"
                        "Maybe if you tried pointing me in the right "+
                        "direction, I might hit something!!!"
                    );
                }
                if(yy == 10) {
                    if((int)owner->query_hp() < 50) {
                        tell_object(owner,"%^RED%^%^BOLD%^"
                            "The sword tells you: %^RESET%^"
                            "Umm...might want a little bit of healing "+
                            "here!  Or maybe you're just weak?"
		        );
                    } else {
                        tell_object(owner,"%^RED%^%^BOLD%^"
                            "The sword tells you: %^RESET%^"
                            "Lookin' nice, lookin' nice!  Where'd "+
                            "you get those arms?"
                        );
                    }
                }
            }
            return;
        }
    }
}
int extra_hit(object ob) {
    int xx,dam,cost;
    object rab;
    object vic = environment(TO)->query_current_attacker();
if(!objectp(ob) || !objectp(vic)) return 1;
    if(uses < 0) return 0;
    if(random(8) > 3) return 0;
    xx=random(6)+1;
    switch(xx) {

    case 1:
    message("my_action","%^BOLD%^%^MAGENTA%^"
        "Suddenly, a glowing purple Anvil drops from the sky and bonks "
	+vic->query_cap_name()+
        " on the head!"
        "%^RESET%^"
    ,environment(TO));
    message("other_action","%^BOLD%^%^MAGENTA%^"
        "Suddenly, a glowing purple Anvil drops from the sky and bonks "
	+vic->query_cap_name()+
        " on the head!"
        "%^RESET%^"
    ,environment(ob),(({environment(TO), ob})));
    message("my_action",
        "Suddenly, you are bonked on the head by a glowing purple "
	"Anvil!"
        "%^RESET%^"
    ,ob);
    vic->do_damage("head",random(6)+1);
    uses = uses - random(3)+1;
    new( OPATH "anvil.c" )->move(environment(ETO));
    return 1;

    case 2:
    dam = random((int)environment(TO)->query_stats("dexterity"))/4;
    message("my_action","%^BOLD%^%^GREEN%^"
        "The sword yells: %^RESET%^BOO!!\n"
        "%^BLUE%^You manage to land a lucky blow as your opponent "
	"is surprised by the sound!"
        "%^RESET%^"
    ,environment(TO));
    message("other_action","%^BOLD%^%^GREEN%^"
        "The sword wielded by "
        +environment(TO)->query_cap_name()+" yells: %^RESET%^BOO!!"
        "%^RESET%^"
    ,environment(ob),(({environment(TO), ob})));
    message("my_action","%^BOLD%^%^GREEN%^"
        "You are startled as the sword wielded by "
        +environment(TO)->query_cap_name()+" yells: %^RESET%^BOO!!"
        "%^RESET%^"
    ,ob);
    return dam;

    case 3:
    dam = 10 - random((int)environment(TO)->query_level());
    if(dam < 0) dam = 1;
    message("my_action","%^BOLD%^%^RED%^"
        "The sword tells you: %^RESET%^"
        "WEENIES SHALL RULE THE LANDS!!!"
        "%^RESET%^"
    ,environment(TO));
    message("other_action","%^BOLD%^%^MAGENTA%^"
        +environment(TO)->query_cap_name()+" gets a startled look on "
	+environment(TO)->query_possessive()+
        " face while swinging a strange sword!"
        "%^RESET%^"
    ,environment(ob),(({environment(TO), ob})));
    message("my_action","%^BOLD%^%^MAGENTA%^"
        +environment(TO)->query_cap_name()+" gets a startled look on "
	+environment(TO)->query_possessive()+
        " face while swinging a strange sword!"
        "%^RESET%^"
    ,ob);
    uses = uses - 1;
    return dam;

    case 4:
    if((int)environment(TO)->query_hp() < 10) {
    message("my_action","%^BOLD%^%^RED%^"
        "The sword shouts: %^RESET%^RETREAT!! RETREAT!! You're about to die!"
        "%^RESET%^"
    ,environment(TO));
    dam = random(1)+1;
    uses = uses -1;
    return dam;
    }
  case 5:

  if (!random(2)) {
    message("my_action","%^BOLD%^%^RED%^"
        "The sword tells you: %^RESET%^We need help...I will summon "
        "a Demon Prince to aid us!!!\n"
        "%^YELLOW%^A small rabbit appears and attacks your foe!\n"
        "%^BOLD%^%^RED%^The sword tells you: %^RESET%^"
        "ACK! Thats not what I had in mind at all!"
    ,environment(TO));
    message("other_action","%^YELLOW%^"
        "A small rabbit appears near "
        +environment(TO)->query_cap_name()+
        " and attacks "
        +ob->query_cap_name()+"!"
        "%^RESET%^"
    ,environment(ob),(({environment(TO), ob})));
    message("my_action","%^YELLOW%^"
        "A small rabbit appears near "
        +environment(TO)->query_cap_name()+" and attacks you!"
        "%^RESET%^"
    ,ob);
    new( MPATH "rabbit.c")->move(environment(ETO));
    if(rab = present("rabbit",environment(ETO))) {
        rab->force_me("kill "+vic->query_name());
        rab->set_property("knock unconscious",1);
    }
  } else {
    message("my_action","%^BOLD%^%^RED%^"
        "The sword tells you: %^RESET%^We need help...I will summon "
        "a Demon Prince to aid us!!!\n"
        "%^YELLOW%^A small rabbit appears and attacks you!!!\n"
        "%^BOLD%^%^RED%^The sword tells you: %^RESET%^"
        "ACK! Thats not what I had in mind at all!"
    ,environment(TO));
    message("other_action","%^YELLOW%^"
        "A small rabbit appears near "
        +environment(TO)->query_cap_name()+
        " and attacks "
        +ETO->query_cap_name()+"!"
        "%^RESET%^"
    ,environment(ob),(({environment(TO)})));
    message("my_action","%^YELLOW%^"
        "A small rabbit appears near "
        +"you and attacks!!!"
        "%^RESET%^"
    ,ETO);
    new( MPATH "rabbit.c")->move(environment(ETO));
    if(rab = present("rabbit",environment(ETO))) {
        rab->force_me("kill "+ETO->query_name());
    }
  }
    uses = uses - 2;
    return 1;
    case 6:
    message("my_action","%^BOLD%^%^RED%^"
        "The sword tells you: %^RESET%^Hmmm...wonder what this does...\n"
        "%^RESET%^%^GREEN%^Manna falls from the sky!\n"
        "%^BOLD%^%^RED%^The sword tells you: %^RESET%^"
	"Wow...uhhh...cool I guess."
    ,environment(TO));
    message("other_action","%^GREEN%^"
        "Manna falls from the sky!"
        "%^RESET%^"
    ,environment(ob),(({environment(TO), ob})));
    message("my_action","%^GREEN%^"
        "Manna falls from the sky!"
        "%^RESET%^"
    ,ob);
    new(OPATH "manna.c")->move(environment(ETO));
    uses = uses - 1;
    return 1;
    }
}

int extra_wield() {
    object tp;
    tp = this_player();
    if (!tp) return 0;
        write(
	    "%^BOLD%^%^MAGENTA%^You wield the sword and fall to the ground laughing!"
	    "%^RESET%^"
        );
        say(
	    "%^BOLD%^%^MAGENTA%^"+ETOQCN+" wields a sword and begins to "
	    "laugh like an utter idiot!\n%^RESET%^"
	    "%^RED%^Suddenly "+ETOQCN+" looks you right in the face and laughs "
	    "even louder!%^RESET%^"
        );
    return 1;
}
int extra_unwield() {
    object tp;
    tp = ETO;
    if (!tp) return 0;
    tell_object(ETO,
	"%^BOLD%^%^RED%^The sword tells you: %^RESET%^WHY?!? What...what...arrrggghhh....YOU DON'T LOVE ME ANYMORE???"
    );
    return 1;
}
