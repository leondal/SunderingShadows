#include <std.h>
#include <daemons.h>
#include "token_hunt.h"

inherit FILE_PATH"token_vendor.c";

int timer;

void create() 
{
    ::create();
    set_name("Jezulfin");
    set_id( ({ "Jezulfin","vendor", "gnome", "shopkeeper","jezulfin"}) );
    set_short("%^RESET%^%^CYAN%^Jezulfin - a small %^YELLOW%^gold skinned %^RESET%^%^CYAN%^gnome%^RESET%^");
    set_long("%^RESET%^%^CYAN%^Jezulfin is little gnome at three feet and change with "
        "dark %^YELLOW%^gold skin%^RESET%^%^CYAN%^. Slim and trim, his head seems a bit "
        "large for his body, though this may be more due to the %^BOLD%^%^BLACK%^large "
        "nose%^RESET%^%^CYAN%^ and wild mane of %^ORANGE%^chestnut hair %^CYAN%^rather "
        "then any real disproportion in body size. Dressed casually in "
        "%^ORANGE%^browns%^CYAN%^, %^RESET%^grays%^CYAN%^, %^BLUE%^%^BOLD%^blues "
        "%^RESET%^%^CYAN%^and %^BOLD%^%^WHITE%^whites%^RESET%^%^CYAN%^, he looks fairly "
        "neatly put together as far as color coordination goes, though there's a ragged "
        "edge to his wardrobe that suggests a lack of real consideration for appearance.  "
        "Added to this is his shaggy mane of hair, which is wild and completely untamed.  "
        "Half curly, half straight, half kinky and all sticking out in various directions "
        "the soft looking, %^ORANGE%^br%^RESET%^o%^ORANGE%^wn%^RESET%^is%^ORANGE%^h-gr"
        "%^RESET%^a%^ORANGE%^y %^CYAN%^tufts give him a windswept and wild motif. Intense "
        "%^BOLD%^%^BLUE%^blue eyes %^RESET%^%^CYAN%^add to this wildness as they dart about, "
        "glancing at everything and nothing all the time, all most as if he cannot keep his "
        "mind still upon one thing for very long.%^RESET%^");

    set("aggressive", 0);
    set_level(55);
    set_gender("male");
    set_race("gnome");
    set_body_type("human");
    set_size(1);
    set_hd(55,50);
    set_attacks_num(4);
    set_damage(3,10);
    set_max_hp(query_hp());

    set_storage_room(INV_PATH"high_store");
    set_store_type("high");
    fill_storage_room();
}

int word_filter(string str)
{
    int i,result;
    string *hellos  = ({ "hello","hi","greetings","salutations","howdy","'ello","hey"});
    string *affirms = ({ "yes","yeah","ya","yay" });
    string *wagon   = ({ "wagon","cart","here","why" });
    string *stories = ({ "story","shapechanger","shapechangers","token","tokens" });
    string *dino    = ({ "dino","dinosaur","monster","triceratops" });

    for(i=0;i<sizeof(hellos);i++)
    {
        if(strsrch(str,hellos[i]) != -1)
        {
            result = 1;
        }
    }

    for(i=0;i<sizeof(affirms);i++)
    {
        if(strsrch(str,affirms[i]) != -1)
        {
            result = 2;
        }
    }

    for(i=0;i<sizeof(wagon);i++)
    {
        if(strsrch(str,wagon[i]) != -1)
        {
            result = 3;
        }
    }

    for(i=0;i<sizeof(stories);i++)
    {
        if(strsrch(str,stories[i]) != -1)
        {
            result = 4;
        }
    }

    for(i=0;i<sizeof(dino);i++)
    {
        if(strsrch(str,dino[i]) != -1)
        {
            result = 5;
        }
    }
    return result;
}

void talk_func(string str,object ob)
{
    string words;
    int result;

    if(!interactive(ob)) { return; }
    words = FILTERS_D->filter_colors(str);
    words = lower_case(words);
    result = word_filter(str);

    switch(result)
    {
    case 1:
        force_me("say huh? what?  Oh, yes, hello there.  Can I help you?");
        return;
    case 2:
        force_me("emote stares blankly for a moment.");
        force_me("say really?");
        force_me("say uh..");
        force_me("say well what can I help you with?");
        force_me("emote wrings "+TO->QP+" hands together and starts to look excited.");
        force_me("say Do you want to know about my wagon or why I'm here?");
        return;
    case 3:
        force_me("emote grins from ear to ear.");
        force_me("say now THAT is a story for another time.");
        force_me("say but...");
        force_me("emote gestures to his wagon");
        force_me("say me and my brothers have a plan and we've "
            "all got wagons loaded down with rare and powerful "
            "magical items.");
        force_me("say you can see my <list> of wares if you want to.");
        return;
    case 4:
        force_me("say well it's far too long to tell the whole story..");
        force_me("emote seems to consider then bobs his head.");
        force_me("say but I can give you the short version.");
        force_me("emote takes a deep breath");
        force_me("say About thirty years ago, me and my brothers and "
            "my mother and father got the idea to make a new currency for "
            "the Tsarven Empire.  We made these %^BOLD%^boxes%^RESET%^ for "
            "the currency to go in to do away with the hassle of counting "
            "your money.  All you had to do was put the tokens in the box "
            "and touch your box to a vendor and it took care of everything "
            "for you.  It was GENIUS.  The boxes were magic you see, they "
            "could haul an INFINITE amount of tokens inside.  No more "
            "need to carry around wagon loads of gold any time you wanted "
            "to buy something.");
        force_me("emote takes another deep breath.");
        force_me("say Well the tokens never really caught on.  Only a few "
            "of the merchants were interested at all, none of the other ones "
            "were willing to have their money enchanted.  Paranoid I tell you!  "
            "The tokens don't have anymore value than your standard coins to "
            "anyone else, but to me and my brothers they have some sentimental "
            "value.");
        force_me("emote lowers his eyes and sniffs");
        force_me("say You see, mother and father died a few years ago in a "
            "terrible wagon accident.  Not long after that we found out that "
            "a bunch of servants we had hired were actually a cult of "
            "shapeshifters!  They had been stealing the tokens and hording "
            "them.  We think they must be attracted to the magic that "
            "lets the coins change on their own.");
        force_me("giggle");
        force_me("say But it didn't work for those shape shifters like they "
            "thought it would.  While they have the tokens, they are stuck in "
            "whatever shape they were in when they found them.  And they "
            "don't seem to want to part with them, they can't be reasoned "
            "with!");
        force_me("say The tokens are magical, and we're able to track where "
            "they are.  Well, sortof.  We don't know exactly, but we've got "
            "a pretty good idea.");
        force_me("emote points at a list on the side of the wagon");
        force_me("say that list gives their basic location.  If you can bring "
            "back our tokens, we will be willing to trade you these magic "
            "items for them.");
        force_me("emote looks hopeful.");
        return;
    case 5:
        force_me("emote turns and looks at the dinosaur");
        force_me("say what, him?");
        force_me("say he's a big pet, wouldn't hurt a fly!");
        force_me("say he's been with me since I was a little gnome.");
        force_me("say he pulls the wagon and scares away thieves.");
        force_me("emote smiles at the triceratops");
        return;
    default:
        if(random(20)) { return; }
        force_me("emote pinches his nose and looks at the dinosaur.");
        force_me("say eww..  where did I put that shovel.");
        return;
    }
    return;
}

void catch_say(string str) 
{ 
    if(timer > time()) { return; }
    timer = time() + 30;
    call_out("talk_func",1,str,TP); 
}
