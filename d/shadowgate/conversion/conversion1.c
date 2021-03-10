#include <std.h>
inherit ROOM;

void newsg(object targ,int num);

void create()
{
    ::create();
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);

    set_name("within the haze");
    set_short("%^BOLD%^%^BLUE%^Within the Haze%^RESET%^");

    set_long("%^BOLD%^%^BLUE%^Within the Haze%^RESET%^\n"+
        "%^BOLD%^%^CYAN%^You find yourself floating in a haze.  "+
        "Everything seems insubstantial and distant.  Even your "+
        "own body feels out of touch with your consciousness.  "+
        "And yet, as you float in that intangible realm, you "+
        "sense something or someone ordering things.  Even as "+
        "you sense this other force, your memory swirls with "+
        "visions..");

    set_smell("default","\nThere is nothing within the haze "+
        "to smell.");
    set_listen("default","You can hear nothing within the "+
        "haze.");
}

void init()
{
    if(!objectp(TP)) { return; }
    if(avatarp(TP)) { return; }
    ::init();
    call_out("newsg",10,TP,0);
}
 
void newsg(object targ, int num)
{
    object ob;

    if(!objectp(targ)) { return; }
    switch(num)
    {  
    case(0):
        tell_object(targ,"%^BOLD%^%^BLACK%^...Your head jerks "+
        "backwards as you regain consciousness.\n\n");
        break;
    case(1):
        tell_object(targ,"%^BOLD%^%^CYAN%^Shortly after the energy "+
        "ring passes over your head, a %^RESET%^deafening silence "+
        "%^BOLD%^%^CYAN%^overtakes the land.\n\n");
        break;
    case(2):
        tell_object(targ,"%^BOLD%^%^CYAN%^Your ears begin to "+
        "%^RED%^t%^RESET%^%^RED%^h%^BOLD%^%^BLACK%^r%^RED%^ob "+
        "%^CYAN%^and your strength momentarily gives out.\n\n");
        break;
    case(3):
        tell_object(targ,"%^BOLD%^%^CYAN%^You sense the magic in "+
        "your mind, your equipment and the lands around you are "+
        "%^BLACK%^gone%^CYAN%^.\n\n");
        break;
    case(4):
        tell_object(targ,"%^BOLD%^%^CYAN%^Your ears pulse as the "+
        "pressurized %^RED%^BOOM %^CYAN%^catches up behind the "+
        "rapidly vanishing energy pulse carrying with it the last "+
        "few %^RESET%^%^CYAN%^memories %^BOLD%^of the disintegrated "+
        "crew:\n\n");
        break;
    case(5):
        tell_object(targ,"%^BOLD%^%^CYAN%^Your consciousness "+
        "shifts and you find yourself within the mind of a drow "+
        "foreman...\n\n");
        break;
    case(6):
        tell_object(targ,"%^BOLD%^%^BLACK%^He smiles proudly as he "+
        "passes under the eaves of this Underdark metropolis and into "+
        "a wide open hangar. Everywhere he looks he humbly delights "+
        "in the blood and sweat of slave labor. Even he bears the "+
        "motivating scars left by his superior mistress. Only now "+
        "can he understand the shape of the thing looming in the "+
        "darkness of the hangar, but its purpose remains a mystery. "+
        "Smugly, he masks his own ignorance and sneers at a nearby "+
        "gnomish slave: %^BLUE%^'Behold, filth, the falling of a "+
        "new night for the Goddess-Queen. Be thankful of your "+
        "opportunity to do service for your new world.'");
        break;
    case(7):
        tell_object(targ,"\n");
        break;
    case(8):
        tell_object(targ,"\n");
        break;
    case(9):
        tell_object(targ,"%^BOLD%^%^CYAN%^Your consciousness shifts "+
        "and you find yourself within the mind of a gnomish "+
        "servant...\n\n");
        break;
    case(10):
        tell_object(targ,"%^BOLD%^%^GREEN%^She couldn't believe what "+
        "she saw. A platform slithered its way out of the shell of "+
        "that horrible boat. Nightmarish creatures were boarding now..."+
        "dark elves, eye tyrants, mind flayers. Home. She prayed she "+
        "could go home, now that the boat was done. Home now. One "+
        "of the dark elves turned to face her. Oh gods, she choked on "+
        "her prayer as she was effortlessly lifted by the neck and "+
        "dragged up the ramp. She was thrown onto the deck before "+
        "an eye tyrant wearing a funny helmet with cords of light "+
        "extending from it. Though it never moved its mouth, she "+
        "heard the dry words in her mind: %^RED%^'We're going to "+
        "our new home now. We'll need slaves there too.'");
        break;
    case(11):
        tell_object(targ,"\n");
        break;
    case(12):
        tell_object(targ,"\n");
        break;
    case(13):
        tell_object(targ,"%^BOLD%^%^CYAN%^Your consciousness shifts "+
        "and you find yourself within the mind of an illithid "+
        "navigator...\n\n");
        break;
    case(14):
        tell_object(targ,"%^BOLD%^%^MAGENTA%^Cruising speed now. "+
        "Unexpected turbulence, but that could be explained. Several "+
        "calculations of time and distance coursed effortlessly "+
        "through her brain. Of course, they must be approaching the "+
        "border of the inner Weave. It was time to prove the "+
        "superiority of their power. The illithid turned to her "+
        "broodmate: %^YELLOW%^'Quaid, start the Faerzress Reactor!'");
        break;
    case(15):
        tell_object(targ,"\n");
        break;
    case(16):
        tell_object(targ,"\n");
        break;
    case(17):
        tell_object(targ,"%^BOLD%^%^CYAN%^Your consciousness shifts "+
        "and you find yourself within the mind of a beholder "+
        "captain...\n\n"); 
        break;
    case(18):
        tell_object(targ,"%^RESET%^%^ORANGE%^He was pleased with "+
        "himself. It was an impressive honor to pilot, and an obvious "+
        "choice. He and his kind can take full view of their "+
        "surroundings, never to be caught off guard by whatever faced "+
        "them on the other side of the Weave. He heard one of the "+
        "illithid squirt and squish at another, and the noisome reactor "+
        "buzzed to life. The deck was filled with that sickly though "+
        "familiar pale violet glow of activated Faerzress. Wait. "+
        "One of his eyestalks went blind. Incredible pressure. He "+
        "knew instinctively that his eye rays went dead. Something "+
        "was wrong. What was that chaos? Where was he? The "+
        "mountainside? %^RED%^'Nooooooooooooooooooo!'");
        break;
    case(19):
        tell_object(targ,"\n");
        break;
    case(20):
        tell_object(targ,"\n");
        break;
    case(21):
        tell_object(targ,"%^BOLD%^%^BLACK%^Everything goes "+
        "dark.\n\n"); 
        break;
    case(22):
        tell_object(targ,"%^BOLD%^%^CYAN%^Slowly you return to "+
        "consciousness.\n\n");
        break;
    case(23):
        tell_object(targ,"%^BOLD%^%^CYAN%^A place of %^WHITE%^"+
        "quiet %^CYAN%^and %^GREEN%^calm%^CYAN%^.\n\n"); 
        break;
    case(24):
        tell_object(targ,"%^BOLD%^%^CYAN%^The energy ring can "+
        "no longer be seen.\n\n"); 
        break;
    case(25):
        tell_object(targ,"%^BOLD%^%^CYAN%^Your ears quiet down "+
        "to a %^RED%^buzz %^CYAN%^and the %^RESET%^%^MAGENTA%^"+
        "magic %^BOLD%^%^CYAN%^around you seems to be struggling "+
        "to reassert itself.\n\n"); 
        break;
    case(26):
        tell_object(targ,"%^BOLD%^%^CYAN%^Not a beast makes a "+
        "noise but your numb ears detect the distant cries of "+
        "frightened voices nearby.\n\n"); 
        break;
    case(27):
        tell_object(targ,"%^BOLD%^%^CYAN%^Suspended in the calm "+
        "air is a gentle rain of %^BOLD%^%^WHITE%^t%^RESET%^"+
        "w%^BOLD%^%^CYAN%^i%^RESET%^%^CYAN%^n%^BOLD%^%^WHITE%^"+
        "kl%^RESET%^%^CYAN%^i%^RESET%^n%^BOLD%^%^WHITE%^g "+
        "%^CYAN%^debris.\n\n"); 
        break;
    case(28):
        tell_object(targ,"%^BOLD%^%^CYAN%^It slowly changes "+
        "from %^RESET%^%^ORANGE%^v%^YELLOW%^i%^BLACK%^b%^RESET%^"+
        "%^ORANGE%^r%^YELLOW%^a%^RESET%^%^ORANGE%^nt g%^BOLD%^"+
        "%^BLACK%^o%^YELLOW%^l%^RESET%^%^ORANGE%^d %^BOLD%^"+
        "%^CYAN%^to a %^RESET%^%^MAGENTA%^s%^GREEN%^i%^MAGENTA%^"+
        "ck%^BLACK%^%^BOLD%^l%^RESET%^%^MAGENTA%^y p%^GREEN%^a"+
        "%^MAGENTA%^le v%^RESET%^i%^BOLD%^%^BLACK%^o%^RESET%^"+
        "%^MAGENTA%^l%^GREEN%^e%^MAGENTA%^t %^BOLD%^%^CYAN%^"+
        "before finally winking %^BLACK%^out%^CYAN%^.\n\n"); 
        break;
    case(29):
        tell_object(targ,"%^BOLD%^%^CYAN%^Like gently falling "+
        "%^WHITE%^snow%^CYAN%^, the matter descends and you "+
        "begin to feel %^GREEN%^whole%^CYAN%^.\n\n"); 
        break;
    case(30):
        tell_object(targ,"%^BOLD%^%^CYAN%^You feel yourself "+
        "moved. Another consciousness guiding you back to life. "+
        "Back to reality.\n\n"); 
        break;
    case(31):
        tell_object(targ,"%^BOLD%^%^CYAN%^You are flooded with "+
        "the sense that you have %^GREEN%^survived%^CYAN%^. Even "+
        "as you feel %^YELLOW%^changed%^CYAN%^.\n\n"); 
        break;
    case(32):
        targ->move("/d/shadowgate/conversion/conversion2");
        targ->force_me("look");
        break;
    }
    num++;
    if(!present(targ,TO)) return;
    call_out("newsg",10,targ,num);
    return;
}  

void summon_player(object ob)
{
    ob->move(TO);
    ob->force_me("look");
    return;
}

void summon_me(object ob)
{
    call_out("summon_player",0,ob);
    return;
}