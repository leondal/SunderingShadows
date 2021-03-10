#include <std.h>
#include "area_stuff.h"
#include <daemons.h>

#define RROOMS1 ({"upper4", "upper5", "upper6", "upper7", "upper9", "upper8", "upper10", "upper11", "upper12", "upper13", "upper14", "upper15"})

#define RROOMS2 ({"mid1", "mid2", "mid3", "mid4", "mid5", "mid6", "mid7", "mid8", "mid9", "mid10", "mid11"})

#define RROOMS3 ({"lower1", "lower2", "lower3", "lower4", "lower5", "lower6", "lower7", "lower8", "lower9",\
"lower10", "lower11", "lower12", "lower13", "lower14", "lower15"})

#define BOSSROOMS ({"mid2_1", "mid2_2", "mid2_3", "mid2_4", "mid2_5", "mid2_6", "mid2_7",\
"lower2_1", "lower2_2", "lower2_3", "lower2_4", "lower2_5", "lower2_6", "lower2_7"})

inherit CROOM;

void create() 
{
    ::create();
    if(!random(4)) set_property("wild magic", 15);
}

void place_runes()
{
    string *green, *red, *gray, greenr, redr, grayr, *arooms;
    green = SAVE_D->query_array("charu_cavern_rune_green");
    red = SAVE_D->query_array("charu_cavern_rune_red");
    gray = SAVE_D->query_array("charu_cavern_rune_gray");
    arooms = RROOMS1 + RROOMS2 + RROOMS3;
    if(sizeof(green)) 
    {
        greenr = green[0];
        if(member_array(greenr, RROOMS1) != -1) arooms -= RROOMS1;
        if(member_array(greenr, RROOMS2) != -1) arooms -= RROOMS2;
        if(member_array(greenr, RROOMS3) != -1) arooms -= RROOMS3;
    }
    if(sizeof(red)) 
    {
        redr = red[0];
        if(member_array(redr, RROOMS1) != -1) arooms -= RROOMS1;
        if(member_array(redr, RROOMS2) != -1) arooms -= RROOMS2;
        if(member_array(redr, RROOMS3) != -1) arooms -= RROOMS3;
    }
    if(sizeof(gray)) 
    {
        grayr = gray[0];
        if(member_array(grayr, RROOMS1) != -1) arooms -= RROOMS1;
        if(member_array(grayr, RROOMS2) != -1) arooms -= RROOMS2;
        if(member_array(grayr, RROOMS3) != -1) arooms -= RROOMS3;
    }
    if(!stringp(greenr)) 
    {
        greenr = arooms[random(sizeof(arooms))];
        if(member_array(greenr, RROOMS1) != -1) arooms -= RROOMS1;
        if(member_array(greenr, RROOMS2) != -1) arooms -= RROOMS2;
        if(member_array(greenr, RROOMS3) != -1) arooms -= RROOMS3;
        SAVE_D->set_value("charu_cavern_rune_green", greenr);
    }
    if(!stringp(redr)) 
    {
        redr = arooms[random(sizeof(arooms))];
        if(member_array(redr, RROOMS1) != -1) arooms -= RROOMS1;
        if(member_array(redr, RROOMS2) != -1) arooms -= RROOMS2;
        if(member_array(redr, RROOMS3) != -1) arooms -= RROOMS3;
        SAVE_D->set_value("charu_cavern_rune_red", redr);
    }
    if(!stringp(grayr)) 
    {
        grayr = arooms[random(sizeof(arooms))];
        SAVE_D->set_value("charu_cavern_rune_gray", grayr);
    }
    return;
}
    


void init()
{
    ::init();
    if(!objectp(TP)) return;
    if(!TP->is_player()) return;
    place_runes();
}

void make_rune(string which)
{
    object ob;
    if(!objectp(TO)) return;
    if(!present("rune", TO)) 
    {  
        ob = new(CROB+"rune");
        ob->make_me(which);
        ob->move(TO);
    }
    if(!present("rune keeper", TO)) 
    {
        ob = new(CRMON+"rune_keeper");
        ob->move(TO);
    }
}

void absorb_oozes()
{
    object *beings;
    int x, flag;
    if(!objectp(TO)) return;
    beings = all_living(TO);
    TO->populate_area();
    if(!sizeof(beings)) return;
    for(x = 0;x < sizeof(beings);x++)
    {
        if(interactive(beings[x])) 
        {
            if(!(int)beings[x]->query("absorb notified") || (int)beings[x]->query("absorb notified") < time())
            {           
                flag = 1;
                beings[x]->delete("absorb notified");
                beings[x]->set("absorb notified", time() + 3600);
                continue;
            }
        }
        if(beings[x]->id("chsaidemob9x"))
        {
            tell_room(TO, "%^BOLD%^%^RED%^A strange sucking noise echoes through the "+
            "cavern as "+beings[x]->query_short() +"%^BOLD%^%^RED%^ is suddenly "+
            "absorbed by the cavern walls!%^RESET%^");
            beings[x]->move("/d/shadowgate/void");
            if(objectp(beings[x])) beings[x]->remove();
            flag--;
            continue;
        }
        if(beings[x]->id("chsaidemob8x"))
        {
            tell_room(TO, "%^BOLD%^%^RED%^A %^BOLD%^%^WHITE%^D%^BOLD%^%^GREEN%^EA%^BOLD%^"+
            "%^WHITE%^F%^BOLD%^%^GREEN%^E%^BOLD%^%^WHITE%^N%^BOLD%^%^GREEN%^I%^BOLD%^%^WHITE%^"+
            "NG%^BOLD%^%^RED%^ scream erupts from "+beings[x]->query_short()+"%^BOLD%^%^RED%^ "+
            "as "+beings[x]->QS+" glances around futilely before running away in unmistakeable"+
            " terror!%^RESET%^");
            beings[x]->move("/d/shadowgate/void");
            if(objectp(beings[x])) beings[x]->remove();
            flag--;
            continue;
        }
        continue;
    }
    if(flag) 
    {
        tell_object(TO, "%^BOLD%^%^RED%^A strange sucking noise suddenly echoes through "+
        "the entire cavern!%^RESET%^");
        return;
    }
    return;    
}

void place_boss()
{
    string *tmp, bossr = "", *rooms;
    int bossd = 0, x;
    object boss;
    //tell_object(TO, "base_name(TO) = "+identify(base_name(TO)));
    tmp = SAVE_D->query_array("charu_cavern_boss_location");
    if(sizeof(tmp)) bossr = tmp[0];
    if(!stringp(bossr) || bossr == "")
    {
        bossr = BOSSROOMS[random(sizeof(BOSSROOMS))];
        SAVE_D->remove_array("charu_cavern_boss_location");
        SAVE_D->set_value("charu_cavern_boss_location", CRROOMS+bossr);
    }
    //tell_object(TO, "checking to see if rooms are equal..");
   // tell_object(TO, "boss room = "+bossr);
    if(base_name(TO) == bossr) 
    {   
        //tell_object(TO, "They are equal");
        if(!objectp(boss = present("saideccbossmob", TO))) 
        {
            new(CRMON+"abomination")->move(TO);
        }
    }
    rooms = get_dir(CRROOMS+"*.c");
    for(x = 0;x < sizeof(rooms);x++)
    {
        rooms[x] = CRROOMS + rooms[x];
        if(!file_exists(rooms[x])) continue;
        if(find_object(rooms[x])) rooms[x]->absorb_oozes();        
    }
    
}  
    
void reset()
{
    string redr = "", greenr = "", grayr = "", *tmp;
    int redd = 0, greend = 0, grayd = 0, bossd = 0;
    ::reset();
    tmp = SAVE_D->query_array("charu_cavern_boss_delay");
    if(sizeof(tmp)) bossd = tmp[0];
    if(time() < bossd) return;
    place_runes();
    tmp = SAVE_D->query_array("charu_cavern_rune_red_delay");
    if(sizeof(tmp)) redd = tmp[0];
    tmp = SAVE_D->query_array("charu_cavern_rune_green_delay");
    if(sizeof(tmp)) greend = tmp[0];
    tmp = SAVE_D->query_array("charu_cavern_rune_gray_delay");
    if(sizeof(tmp)) grayd = tmp[0];
    
    if(time() >= redd) 
    {
        tmp = SAVE_D->query_array("charu_cavern_rune_red");
        if(sizeof(tmp)) redr = tmp[0];
        SAVE_D->remove_value("charu_cavern_rune_red_delay");
    }
    if(time() >= greend) 
    {
        tmp = SAVE_D->query_array("charu_cavern_rune_green");
        if(sizeof(tmp)) greenr = tmp[0];
        SAVE_D->remove_value("charu_cavern_rune_green_delay");
    }
    if(time() >= grayd)
    {
        tmp = SAVE_D->query_array("charu_cavern_rune_gray");
        if(sizeof(tmp)) grayr = tmp[0];
        SAVE_D->remove_value("charu_cavern_rune_gray_delay");
    }
    if(time() <= grayd && time() <= redd && time() <= greend) place_boss();
    if(base_name(TO) == CRROOMS + redr) make_rune("red");
    else if(base_name(TO) == CRROOMS + greenr) make_rune("green");
    else if(base_name(TO) == CRROOMS + grayr) make_rune("gray");
}

int check_delay()
{
    string *tmp, bossr = "";
    int bossd = 0, redd = 0, greend = 0, grayd = 0;
    tmp = SAVE_D->query_array("charu_cavern_boss_delay");
    if(sizeof(tmp)) bossd = tmp[0];
    tmp = SAVE_D->query_array("charu_cavern_boss_location");
    if(sizeof(tmp)) bossr = tmp[0];
    tmp = SAVE_D->query_array("charu_cavern_rune_red_delay");
    if(sizeof(tmp)) redd = tmp[0];
    tmp = SAVE_D->query_array("charu_cavern_rune_green_delay");
    if(sizeof(tmp)) greend = tmp[0];
    tmp = SAVE_D->query_array("charu_cavern_rune_gray_delay");
    if(sizeof(tmp)) grayd = tmp[0];
    if(time() <= grayd && time() <= redd && time() <= greend) return 1;
    if(time() > bossd) 
    {
        SAVE_D->remove_array("charu_cavern_boss_delay");
        //location should be removed on his death - Saide
//        SAVE_D->remove_array("charu_cavern_boss_location");
        return 0;
    }
    return 1;
}
