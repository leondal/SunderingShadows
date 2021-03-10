#include <std.h>
#include <daemons.h>
inherit BARKEEP;

string strip_colors(string sh)
{
    string output = "", *list = ({});
    string *words = ({});
    int i;
    if(!sh) 
    {
        return output;
    }
    words = explode(sh, "%^");
    
    list +=({"RED", "YELLOW", "BLUE",
    "GREEN", "MAGENTA", "ORANGE", "CYAN", "BLACK", "WHITE"});

    list += ({ "B_RED", "B_YELLOW", "B_BLUE", "B_GREEN",
    "B_MAGENTA", "B_ORANGE", "B_CYAN", "B_BLACK", "B_WHITE"});

    list += ({"BOLD", "FLASH", "RESET"});

    for(i = 0;i < sizeof(list);i++)
    {
        words = words - ({ list[i] });
    }
    output = implode(words,"");
    return output;
}


void create() 
{
    ::create();
    set_name("Henderson");
    set_id( ({ "henderson", "friendly host", "host", "helpful host", "hhousehost"}) );
    set_short("Henderson, The Helpful Host");
    
    set_long("%^BOLD%^%^WHITE%^This man stands close to six feet tall. "+
    "He carries himself with an obvious air of pride, as if he is "+
    "pleased with his place in life. He wear a spotless white "+
    "suit that almost shines. It is buttoned and kept always in "+
    "place. His face is smooth and handsome with brilliant green "+
    "eyes and cropped dark brown hair that only serves to accentuate "+
    "his perfectly squared jawline. An aura of kindness radiates about "+
    "him and upon seeing you he motions to a <%^BOLD%^%^CYAN%^menu"+
    "%^BOLD%^%^WHITE%^> that he holds at the ready, suggesting that "+
    "all you would have to do is ask and he would show it to you.%^RESET%^");
    
    set_race("human");
    set_stats("strength",17);
    set_alignment(6);
    set_gender("male");
    set("aggressive",0);
    set_level(28);
    set_hd(28,2);
    set_hp(330);
    set_max_hp(330);
    set_stats("intelligence",15);
    set_stats("wisdom",12);
    set_stats("dexterity",13);
    set_stats("constitution",11);
    set_stats("charisma",10);
    set_new_exp(28, "very low");
    set_body_type("human");
    set_currency("gold");
    set_menu(({"burningdeath", "water", "spring water", "dark roast coffee", "slab of meat", "mysterious sandwich", "hunk of leg"}),
        ({ "alcoholic", "water", "water", "caffeine", "food", "food", "food"}),
        ({ 25, 1, 2, 10, 50, 3, 15}));

    set_my_mess(
    ({"You chug the thick drink and groan as it burns down your throat and into your guts.\n",
        "The water quenches your thirst.\n",
        "The crisp cool spring water soothes your thirst.\n",
        "The dark roast coffee perks you up!\n",
        "The slab of meat is tender but you are not sure what it is.\n",
        "The sandwich is quite tasty despite the fact that the meat is a mstery.\n",
        "The hunk of leg is moist and tender, even if you can't identify the creature it came from.\n"})
    );

    set_your_mess(
    ({
        "chugs the thick drink and groans loudly\n",
        "guzzles a glass of water.\n",
        "enjoys a glass of crisp clear spring water.\n",
        "sips the dark roast coffee.\n",
        "tears into the slab of meat\n",
        "takes several bites from the sandwich\n",
        "tears into the hunk of leg\n"
        })
    );

    set_menu_short(({
    "A burningdeath",
    "A glass of water",
    "A glass of spring water",
    "A cup of dark roast coffee",
    "A slab of meat",
    "A mystery meat sandwich",
    "A hunk of leg"
    }));

    set_menu_long(
    ({
        "A thick and odorless drink.\n",
        "A clear and filtered water.\n",
        "A crisp clear and cool water, imported from some distant spring.\n",
        "A perfectly blended and strong coffee. Sure to help sober you up a bit.\n",
        "A slab of tender mystery meat.\n",
        "A large mystery meat sandwich.\n",
        "A large hunk of leg from an unknown donor.\n" 
    }));
}

void catch_say(string msg)
{
    ::catch_say(msg);
    if(interactive(TP)) 
    {
        call_out("response",1,msg,TP);
    }
}

void menu(object targ)
{
    object ob;
    string *menu_item, melnmarn, *names;
    int length, x;
    if(!objectp(TO)) return;
    if(!objectp(targ)) return;
             
    menu_item = TO->query_menu();
    length = sizeof(menu_item);
    tell_object(targ, TO->QCN+"%^BOLD%^%^BLUE%^ shows you the following menu.\n");
	
    message("Ninfo",
        "%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-%^RESET%^\n", targ);
    while(length--)
    {
        melnmarn = sprintf("       %%^BOLD%%^%%^RED%%^ %-20s  %2d %%^BOLD%%^%%^YELLOW%%^gold pieces.",
        capitalize(menu_item[length]),(int)TO->get_price(menu_item[length]));
        write(melnmarn);
    }
    message("Ninfo",
    "%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-%^RESET%^\n", targ);
    message("Ninfo", "<buy menu_name> will get you that item.\n", targ);
    return 1;
}

void response(string msg, object ob)
{
    if(!objectp(ob)) return;
    if(!stringp(msg)) return;
    msg = strip_colors(msg);


    if(strsrch(msg,"menu") != -1) 
    {
        command("speak common");
        command("speech speak fluently");
        command("say As you wish!");
        tell_object(ob, TO->query_short()+" approaches and shows you a menu.");

        if(!ob->query_invis()) 
        {
            tell_room(ETO, TO->query_short() + " approaches "+ob->QCN+" and shows "+
            ob->QO+" a menu.", ob);
        }
        menu(ob);
        return;
    }
}
