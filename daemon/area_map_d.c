/*============================================
Maybe game-wide area maps? Pondering how possible this would be without 
having to recode a lot of stuff

Saide, November 2016

=============================================*/
#include <std.h>
inherit DAEMON;

void build_grid(mapping MyMap)
{
    int z, b, len, x, y;
    string *myRooms, sym, which, tRoom;
    mapping MY_GRID;
    if(!mapp(MyMap)) return ([]);
    MY_GRID = ([]);
    myRooms = keys(MyMap);
    for(z = 0;z < sizeof(myRooms);z++)
    {
        which = myRooms[z];
        if(which == "x-size")
        {
            x = MyMap["x-size"];
            continue;
        }
        else if(which == "y-size")
        {
            y = MyMap["x-size"];
            continue;
        }
        MY_GRID += ([ which : (["file" : MyMap[which]["file"], "symbol" : MyMap[which]["symbol"], "color" : MyMap[which]["color"]]), ]);
        continue;
    }
    if(x > y) y = x;
    if(y > x) x = y;
    for(z = 1;z < x;z++)
    {
        for(b = 1;b < y;b++)
        {
            if(!mapp(MY_GRID[z+"-"+b]))
            {
                MY_GRID += ([ z+"-"+b : (["file" : "NIL", "symbol" : "   ", "color" : "NIL"]), ]);
                continue;
            }
            continue;
        }
        continue;
    }
    MY_GRID += (["x-size" : x, "y-size" : y]);
    return MY_GRID;
}

mixed build_map(mapping MyMap, object who)
{
    string *tmp, tmp2, which, loc, myEnv;
    int x, y, grid_y, grid_x;
    if(!mapp(MyMap)) return 0;
    tmp = ({"\n%^BOLD%^%^GREEN%^       N\n\n   W - | - E\n\n       S%^RESET%^\n"});    
    if(!MyMap["y-size"]) { grid_y = 20; } //default
    else grid_y = MyMap["y-size"];
    if(!MyMap["x-size"]) { grid_x = 20; } //default
    else grid_x = MyMap["x-size"];    
    if(objectp(who))
    {
        if(objectp(environment(who))) myEnv = base_name(environment(who));
    }
    for(y = 1;y < grid_y;y++)
    {
        tmp2 = "";
        for(x = 1;x < grid_x;x++)
        {
            which = x + "-" + y;
            if(stringp(myEnv))
            {
                if(myEnv == MyMap[which]["file"] ||
                myEnv == MyMap[which]["file"]+".c")
                {
                    tmp2 += "%^BOLD%^%^RED%^"+MyMap[which]["symbol"] +"%^RESET%^";
                    loc = "%^BOLD%^%^RED%^"+MyMap[which]["symbol"] +"%^RESET%^";
                    continue;
                }
            }
            if(MyMap[which]["color"] != "NIL") tmp2 += MyMap[which]["color"] + MyMap[which]["symbol"]+"%^RESET%^";
            else tmp2 += MyMap[which]["symbol"]+"%^RESET%^";
            continue;
        }
        tmp += ({tmp2});        
    }
    if(stringp(loc)) tmp += ({"\n\n%^BOLD%^%^WHITE%^Map Legend   (Your Location: "+loc+")\n"});
    else tmp += ({"\n\n%^BOLD%^%^WHITE%^Map Legend\n"});
    return tmp;
}