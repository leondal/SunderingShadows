//  A nice rabbit
// Pator@ShadowGate
// 04/19/95
#include <std.h>

inherit "/std/monster";

string CASTLE = "/realms/pator/castle/";

mapping flags;



create() {
      ::create();
      set_name("rabbit");
      set_id(({"rabbit"}));
      set_short("A nice rabbit");
      set_long(
@RABBIT
 This is a nice little rabbit with a white tail.  You notice that it is not afraid of you and it is not afraid of you killing it because it is a well bred rabbit just for newbies to prove their skill.
RABBIT
);
      set("race","animal");
      set_gender("male");
      set_body_type("quadruped");
      set_alignment(3);
      set_level(2);
      set_hd(2,0);
      set("aggressive",0);
      set_size(1);
      set_stats("intelligence",2);
      set_stats("wisdom",2);
      set_stats("strength",3);
      set_stats("dexterity",4);
      set_stats("constitution",3);
      set_stats("charisma",5);
      set_hp(10);
      set_max_hp(query_hp());
      set_sp(8);
      set_max_sp(query_sp());
      set_max_mp(0);
      set_mp(query_max_mp());
      add_money("silver",random(3));
    set_exp(1);
//      new(CASTLE+"rabbittail")->move(this_object());
}






// :P
void heart_beat()
{
    object obj;
    ::heart_beat();

    if(!objectp(TO)) { return; }
    if(!objectp(ETO)) { return; }
    if(!objectp(obj=present("garrett",ETO))) { return; }    
    if(random(5000)) { return; }
    
    command("speak common");


    switch(random(7))
    {
    case 0:

        command("emote sits up on his haunches and surveys his surroundings");
        command("emote reaches a little rabbit paw into a hidden pocket and "
            "produces a %^ORANGE%^carrot%^RESET%^");
        command("emoteat garrett munches on the %^ORANGE%^carrot%^RESET%^ before "
            "looking up at $N");
        command("say wassup doc?");
        break;

    case 1:

        command("emote looks covertly between his fellow bunniez");
        command("emoteat garrett peers up at $N");
        command("say the bunniez say that it's time for Ares to get a promotion");
        break;

    case 2:

        command("emote hops around in little circles with his fellow rabbitz");
        break;

    case 3:

        command("emoteat rabbit One of $M's floppy ears straightens above his head");
        command("emoteat garrett sits up and looks at $N");
        command("say the bunniez think that it's time for new Dr. Who.");
        break;

    case 4:

        command("emoteat rabbit ducks to the side and rolls quickly!");
        command("emote leaps high into the air and NINJA CHOPS a flying squirrel!");
        command("emote drops lightly onto his feet and comes to rest on all fours again");
        command("emote nibbles on the end of a fresh carrot");
        command("emoteat garrett peers up at $N without a word");
        break;

    case 5:

        command("emote looks to each of his fellow rabbits and then peers intently around the area");
        command("emote sits back on his haunches and pulls out a uber bunneh laptop of DOOM!");
        command("say it's raid time bunniez");
        tell_room(ETO,"The other rabbitz follow suit, each pulling out their own "
            "bunneh laptop of DOOM!");
        tell_room(ETO,"The bunniez all go into super-bunneh-mode as they log into "
            "WoW and 3-bunneh farm 25 man heroic Trial of The Grand Crusader");
        break;

    case 6:

        command("emote swivels his little bunneh ears around to the side and a light "
            "appears on top of his head!");
        command("emote begins projecting an image of the latest episode of Chuck "
            "on the wall");
        command("emote passes around a bucket of %^ORANGE%^carrot%^RESET%^ flavored "
            "popcorn to his fellow bunniez");
        tell_room(ETO,"The bunniez all sit back and start munching the popcorn as they "
            "watch the show");
        break;
    }
    return;
}


      

