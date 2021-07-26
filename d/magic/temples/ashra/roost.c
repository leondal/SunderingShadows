/*
  Ravens Roost
  
  Temple of Ashra
  Descriptions by Balur/Faceless
  
  -- Tlaloc --
*/

#include <std.h>

inherit "/std/library";
//inherit "/std/templemisc";

void create()
{
    ::create();
    set_property("indoors",1); 
    set_property("light",0);
    //set_temple("ashra");
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_name("Ravens Roost"); 
    set_short("%^MAGENTA%^Ravens Roost%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^The %^RESET%^%^RED%^Raven's roost%^RESET%^ %^BOLD%^%^BLACK%^is truly vast and imposing. The smooth floors are made of %^MAGENTA%^sp%^WHITE%^a%^MAGENTA%^rkling%^RESET%^%^MAGENTA%^ amethyst%^BOLD%^%^BLACK%^, so well polished it seems like they mirror every shadow on their glossy surface. Soft, plush rugs woven from the finest bl%^RESET%^%^WHITE%^a%^BOLD%^%^BLACK%^cks%^RESET%^%^WHITE%^i%^BOLD%^%^BLACK%^lk and v%^RESET%^%^WHITE%^e%^BOLD%^%^BLACK%^lv%^RESET%^%^WHITE%^e%^BOLD%^%^BLACK%^t threads cover the floor where there is furniture like tables or chairs so as to muffle any possible noise and protect the expensive flooring. The walls are panelled from the floor all the way up to the high ceiling with large and heavy slabs of smooth jet black granite. High on their surface, small niches have been carved and c%^YELLOW%^a%^BLACK%^ndles b%^YELLOW%^u%^BLACK%^rn inside them, the only source of l%^YELLOW%^i%^BLACK%^ght other than the soft, but constant %^MAGENTA%^glow %^BLACK%^of the%^RESET%^ %^MAGENTA%^amethyst %^BOLD%^%^BLACK%^floor. Straight ahead, a large ebony library covers the better part of the wall which faces the doorway. In the center of the room a small %^CYAN%^glass display%^BLACK%^ case sits on a shapely pedestal. Other, larger %^RED%^display cabinets %^BLACK%^are tastefully set around the room, showcasing artifacts of the%^RESET%^ %^MAGENTA%^Mistress%^BOLD%^%^BLACK%^. Looking far to your left, a row of five tall and narrow ebony cubicles line up backed against the wall and to your far right five large, %^MAGENTA%^lavish%^BLACK%^, black velvet sitting cushions form a circle around a black cast iron b%^RESET%^%^BOLD%^%^GREEN%^e%^RESET%^%^BOLD%^%^BLACK%^j%^RESET%^%^BLUE%^e%^RESET%^%^BOLD%^%^BLACK%^w%^RESET%^%^MAGENTA%^e%^RESET%^%^BOLD%^%^BLACK%^l%^RESET%^%^RED%^e%^RESET%^%^BOLD%^%^BLACK%^d centerpiece.%^RESET%^");
    set_smell("default","%^MAGENTA%^The heady, sweet aroma of an exotic incense is in the air%^RESET%^");
    set_listen("default","%^MAGENTA%^You can hear the soft whispers of those gathered%^RESET%^");
    set_items(([
        ({"floor"}) : "%^MAGENTA%^This vast room's floor is constructed completely out of amethyst, c%^BOLD%^%^MAGENTA%^l%^WHITE%^e%^MAGENTA%^ar and sp%^WHITE%^a%^MAGENTA%^rkl%^WHITE%^i%^MAGENTA%^ng%^RESET%^%^MAGENTA%^. No ridges or joints can be seen anywhere to indicate that slabs were used for its construction: the result is seamless, effortlessly smooth and continuous. The amethyst seems to %^BOLD%^glow softly%^RESET%^ %^MAGENTA%^from within, bathing the room in a gentle violet%^BOLD%^ aura%^RESET%^%^MAGENTA%^.%^RESET%^",
        ({"rug", "rugs" }) : "The rugs are %^BOLD%^%^BLACK%^black%^RESET%^, %^BOLD%^%^BLACK%^thick%^RESET%^ and %^BOLD%^%^BLACK%^soft%^RESET%^. They are clean and inviting to walk upon, pure luxury underfoot.",
        ({"walls", "wall" }) : "%^BOLD%^%^BLACK%^They are made of enormous slabs of granite. The%^RESET%^ %^BOLD%^%^WHITE%^s%^RESET%^%^WHITE%^i%^RESET%^%^BOLD%^%^BLACK%^lv%^RESET%^%^WHITE%^e%^RESET%^%^BOLD%^%^WHITE%^r%^RESET%^ %^BOLD%^%^BLACK%^fl%^RESET%^%^WHITE%^e%^RESET%^%^BOLD%^%^BLACK%^cks in the beautiful, jet colored gran%^RESET%^%^WHITE%^i%^RESET%^%^BOLD%^%^BLACK%^te make the walls look like an endless, m%^RESET%^%^BOLD%^%^YELLOW%^oo%^RESET%^%^BOLD%^%^BLACK%^nless night sky.%^RESET%^",
        ({"display case", "pedestal" }) : " The %^BOLD%^%^CYAN%^glass%^RESET%^ display case in the center of the room is rather small and cubic, much like the ones found in%^RESET%^ %^BOLD%^%^CYAN%^je%^RESET%^%^BOLD%^%^YELLOW%^w%^RESET%^%^BOLD%^%^CYAN%^elry%^RESET%^ shops. It sits on a%^RESET%^ %^BOLD%^%^BLACK%^shapely%^RESET%^ and rather %^BOLD%^%^BLACK%^intricate ebony%^RESET%^ pedestal. Inside the case, resting on a %^MAGENTA%^violet velvet pillow%^RESET%^, is an elegant piece of head jewelry. A %^BOLD%^%^CYAN%^teardrop%^RESET%^ shaped %^BOLD%^%^WHITE%^sparkling%^RESET%^ %^BOLD%^%^BLACK%^black pearl%^RESET%^ is suspended from a delicate %^BOLD%^%^WHITE%^platinum%^RESET%^ chain. One can imagine the piece would rest on the wearer's forehead. A plaque made of iridescent %^BOLD%^%^BLACK%^bl%^RESET%^%^WHITE%^a%^RESET%^%^BOLD%^%^BLACK%^ck m%^RESET%^%^WHITE%^o%^RESET%^%^BOLD%^%^BLACK%^ther of p%^RESET%^%^WHITE%^e%^RESET%^%^BOLD%^%^BLACK%^arl%^RESET%^ with some writing carved upon it is set below the case.",
        ({"plaque"}) : "%^BOLD%^%^BLACK%^The si%^RESET%^%^WHITE%^l%^RESET%^%^BOLD%^%^WHITE%^v%^RESET%^%^WHITE%^e%^RESET%^%^BOLD%^%^BLACK%^ry letters carved on the bl%^RESET%^%^WHITE%^a%^RESET%^%^BOLD%^%^BLACK%^ck m%^RESET%^%^BOLD%^%^BLACK%^o%^RESET%^%^BOLD%^%^BLACK%^ther of p%^RESET%^%^WHITE%^e%^RESET%^%^BOLD%^%^BLACK%^arl plaque read:%^RESET%^  %^BOLD%^%^BLACK%^Si%^RESET%^%^WHITE%^l%^RESET%^%^BOLD%^%^WHITE%^e%^RESET%^%^WHITE%^n%^RESET%^%^BOLD%^%^BLACK%^ce is a%^RESET%^ %^BOLD%^%^WHITE%^t%^RESET%^%^WHITE%^r%^RESET%^%^BOLD%^%^BLACK%^ue f%^RESET%^%^WHITE%^r%^RESET%^%^BOLD%^%^WHITE%^ie%^RESET%^%^WHITE%^n%^RESET%^%^BOLD%^%^BLACK%^d th%^RESET%^%^WHITE%^a%^RESET%^%^BOLD%^%^WHITE%^t%^RESET%^ %^BOLD%^%^BLACK%^n%^RESET%^%^WHITE%^e%^RESET%^%^BOLD%^%^WHITE%^v%^RESET%^%^WHITE%^e%^RESET%^%^BOLD%^%^BLACK%^r be%^RESET%^%^WHITE%^t%^RESET%^%^BOLD%^%^WHITE%^r%^RESET%^%^WHITE%^a%^RESET%^%^BOLD%^%^BLACK%^ys.%^RESET%^ - Twilight 3:18 Libram of Eternal Night ",
        ({"cabinet", "cabinets" }) : " There are several cabinets, big and small, around the room and all are made of %^BOLD%^%^BLACK%^dark ebony%^RESET%^. Most of them showcase a variety of %^BOLD%^%^CYAN%^artifacts%^RESET%^ and %^BOLD%^%^CYAN%^valuables%^RESET%^ ranging from %^MAGENTA%^old to new%^RESET%^ and from %^RED%^striking to humble%^RESET%^, all obviously %^BOLD%^%^CYAN%^ch%^RESET%^%^BOLD%^%^YELLOW%^e%^RESET%^%^BOLD%^%^CYAN%^rished%^RESET%^ and %^BOLD%^%^CYAN%^pricel%^RESET%^%^BOLD%^%^YELLOW%^e%^RESET%^%^BOLD%^%^CYAN%^ss%^RESET%^. Two of the cabinets are much bigger than the rest and stand out immediately. The one to the left is clearly an %^BOLD%^%^CYAN%^armor display%^RESET%^ and the one to the right a %^RED%^weapon display%^RESET%^. Perhaps you can take a closer look.",
        ({"armor display"}) : "  Displayed here are some of the finest pieces of armor and protective trinkets you have laid eyes upon. They all either carry an enchantment or blessing from the %^MAGENTA%^Mistress of the Night%^RESET%^ or are prefered by her %^MAGENTA%^faithful, clergy and monks%^RESET%^ for their properties. Some of the objects seem rather familiar %^BOLD%^%^YELLOW%^- perhaps legendary -%^RESET%^ like the %^BOLD%^%^BLACK%^armor of pure ebony%^RESET%^ which sits on the shelf next to a %^MAGENTA%^violet robe%^RESET%^ that seems almost ragged by time, yet retains a %^MAGENTA%^glow of importance%^RESET%^. As you turn to move on you finally notice there are several items that are not immediately obvious to the eye, like the %^BOLD%^%^BLACK%^jet black ring%^RESET%^ that appears to absorb the light and the %^BOLD%^%^BLACK%^black leather cloak%^RESET%^ which sometimes shifts like a %^BOLD%^%^BLACK%^shadow%^RESET%^. ",
        ({"weapon display"}) : "This cabinet contains a large array of weapons - all well polished and cared for. It has been divided in equal parts, the higher one displaying the blunt weapons and the lower the sharp ones. Your eye is caught immediately by a very %^BOLD%^%^BLACK%^dark mace%^RESET%^ standing upright next to a %^BOLD%^%^BLACK%^chakram%^RESET%^ that seems to rouse images of the %^BLUE%^night%^RESET%^ when being looked upon. The sharp weapons start with the small blades, among which a peculiar %^BOLD%^%^BLACK%^wh%^RESET%^%^RED%^i%^RESET%^%^BOLD%^%^BLACK%^p-d%^RESET%^%^RED%^a%^RESET%^%^BOLD%^%^BLACK%^gg%^RESET%^%^RED%^e%^RESET%^%^BOLD%^%^BLACK%^r%^RESET%^ has a prominent position. Underneath it, amongst the larger blades, a %^BOLD%^%^BLACK%^sh%^RESET%^%^WHITE%^a%^RESET%^%^BOLD%^%^BLACK%^dowy%^RESET%^, %^BOLD%^%^BLACK%^d%^RESET%^%^WHITE%^u%^RESET%^%^BOLD%^%^BLACK%^ll%^RESET%^ %^BOLD%^%^WHITE%^s%^RESET%^%^WHITE%^i%^RESET%^%^BOLD%^%^BLACK%^lv%^RESET%^%^WHITE%^e%^RESET%^%^BOLD%^%^WHITE%^r%^RESET%^ short-sword lies flat on the shelf below a %^BOLD%^%^WHITE%^s%^RESET%^%^WHITE%^c%^RESET%^%^BOLD%^%^BLACK%^imit%^RESET%^%^WHITE%^a%^RESET%^%^BOLD%^%^WHITE%^r%^RESET%^ with a %^BLUE%^bejewelled%^RESET%^ hilt.",
        ({"centerpiece", "raven" }) : "   Made of %^BOLD%^%^BLACK%^black cast iron%^RESET%^, the centerpiece is the likeness of a %^BOLD%^%^BLACK%^majestic raven%^RESET%^. The bird rises at almost four and a half feet tall and its wings are preparing to outstretch. %^BOLD%^%^GREEN%^Emeralds%^RESET%^, %^MAGENTA%^amethysts%^RESET%^ and %^BLUE%^sapphires%^RESET%^ form a double line on the outer lines of the wings and %^RED%^rubies%^RESET%^ are set as %^BOLD%^%^RED%^flaming%^RESET%^ eyes. The large beak is open and a tiny sharp spike of %^RED%^ruby%^RESET%^ protrudes from its depths, seemingly the bird's %^BOLD%^%^RED%^tongue%^RESET%^.",
        ({"tongue", "spike" }) : "  It seems as though it could be manipulated, but that %^BOLD%^%^WHITE%^would%^RESET%^ be painful.",
        ({"cubicles"}) : "The cubicles, %^BOLD%^%^BLACK%^tall and narrow%^RESET%^, line up against the wall. They look a bit like %^BOLD%^%^BLACK%^confessionals%^RESET%^, but upon opening one of the doors and looking inside, you see no mesh openings to allow conversation with the %^BOLD%^%^BLACK%^neighboring box%^RESET%^. The interior is as austere as their exterior, containing only an uncomfortable-looking %^BOLD%^%^BLACK%^plain pew%^RESET%^ made of %^BOLD%^%^BLACK%^dark ebony%^RESET%^, like the rest of the small %^BOLD%^%^BLACK%^enclosure%^RESET%^.",
    ]));
    set_exits(([
        "west" : "/d/magic/temples/ashra/chapel",
    ]));
}

void init()
{
    ::init();
    add_action("push", "push");
}

int push(string str)
{
    if(!str || (str != "spike" && str != "tongue"))
        return 0;
    
    tell_object(this_player(), "The %^BOLD%^%^RED%^ruby spike%^RESET%^ is extremely sharp and slips into your thumb like a %^BOLD%^%^YELLOW%^hot knife in butter%^RESET%^. As you pull back in pain, a %^RED%^drop of blood%^RESET%^ from your thumb slides into the %^BOLD%^%^BLACK%^bird's throat%^RESET%^ and seconds later an audible click is emitted from the depths of its %^BOLD%^%^BLACK%^iron belly%^RESET%^.");
    tell_room(environment(this_player()), "As " + this_player()->QCN + " tries to push the %^BOLD%^%^RED%^ruby spike%^RESET%^, " + this_player()->QP + " pricks " + this_player()->query_possessive() + " thumb. The %^RED%^drop of blood%^RESET%^ from his/her thumb slides into the %^BOLD%^%^BLACK%^bird's throat%^RESET%^ and seconds later an audible click is emmited from the depths of its %^BOLD%^%^BLACK%^iron belly%^RESET%^.", ({ this_player() })); 
    
    call_out("push_next", 2, this_player());
    return 1;
}

int push_next(object player)
{
    if(!player)
        return 1;
    
    tell_room(environment(player), "A %^BOLD%^%^WHITE%^soft mist%^RESET%^ starts floating out of the %^BOLD%^%^BLACK%^raven's%^RESET%^ beak and begins to slowly cloud the room. A heavy, %^BOLD%^%^MAGENTA%^sweet aroma%^RESET%^ of %^MAGENTA%^hibiscus%^RESET%^ and %^BOLD%^%^WHITE%^musk%^RESET%^ fills your nostrils and almost overpowers you with its sudden %^MAGENTA%^intensity%^RESET%^. Your senses are %^BOLD%^%^CYAN%^heightened%^RESET%^ and you feel you could cross the boundary that seperates %^BOLD%^%^CYAN%^reality%^RESET%^ and %^BOLD%^%^CYAN%^hallucination%^RESET%^ any time you chose to.");
    return 1;
}

    /*
    set_door(" ","chapel"," ",0);
    set_door_description(" ", "   ");

push spike/push tongue: The %^BOLD%^%^RED%^ruby spike%^RESET%^ is extremely sharp and slips into your thumb like a %^BOLD%^%^YELLOW%^hot knife in butter%^RESET%^. As you pull back in pain, a %^RED%^drop of blood%^RESET%^ from your thumb slides into the %^BOLD%^%^BLACK%^bird's throat%^RESET%^ and seconds later an audible click is emitted from the depths of its %^BOLD%^%^BLACK%^iron belly%^RESET%^. 

*effect* A %^BOLD%^%^WHITE%^soft mist%^RESET%^ starts floating out of the %^BOLD%^%^BLACK%^raven's%^RESET%^ beak and begins to slowly cloud the room. A heavy, %^BOLD%^%^MAGENTA%^sweet aroma%^RESET%^ of %^MAGENTA%^hibiscus%^RESET%^ and %^BOLD%^%^WHITE%^musk%^RESET%^ fills your nostrils and almost overpowers you with its sudden %^MAGENTA%^intensity%^RESET%^. Your senses are %^BOLD%^%^CYAN%^heightened%^RESET%^ and you feel you could cross the boundary that seperates %^BOLD%^%^CYAN%^reality%^RESET%^ and %^BOLD%^%^CYAN%^hallucination%^RESET%^ any time you chose to. 

(others see) As <name> tries to push the %^BOLD%^%^RED%^ruby spike%^RESET%^, he/she pricks his/her thumb. The %^RED%^drop of blood%^RESET%^ from his/her thumb slides into the %^BOLD%^%^BLACK%^bird's throat%^RESET%^ and seconds later an audible click is emmited from the depths of its %^BOLD%^%^BLACK%^iron belly%^RESET%^. 

A %^BOLD%^%^WHITE%^soft mist%^RESET%^ starts floating out of the %^BOLD%^%^BLACK%^raven's%^RESET%^ beak and begins to slowly cloud the room. A heavy, %^BOLD%^%^MAGENTA%^sweet aroma%^RESET%^ of %^MAGENTA%^hibiscus%^RESET%^ and %^BOLD%^%^WHITE%^musk%^RESET%^ fills your nostrils and almost overpowers you with its sudden %^MAGENTA%^intensity%^RESET%^. Your senses are %^BOLD%^%^CYAN%^heightened%^RESET%^ and you feel you could cross the boundary that seperates %^BOLD%^%^CYAN%^reality%^RESET%^ and %^BOLD%^%^CYAN%^hallucination%^RESET%^ any time you chose to. 
*/