#include <std.h>
#include "/d/newbie/newbie.h"

inherit OBJECT;

mapping MAP_GRID, MY_GRID;
void init(){
   ::init();
   add_action("read_func","read");
}
void create()
{
   ::create();
   set_id(({"map","newbie town map"}));
   set_name("map");
   set("short","A map of Offestry");
   set("long","This is a map. You should read it.");
   set_weight(0);
   set_value(0);
   
   MAP_GRID = ([MAINTOWN"nstreet3" : (["x-coord" : 9, "y-coord" : 5, "symbol" : " # ", "color" : "%^BOLD%^%^YELLOW%^"]),
   MAINTOWN"nstreet2" : (["x-coord" : 9, "y-coord" : 6, "symbol" : " | ", "color" : "%^BOLD%^%^WHITE%^"]), 
   MAINTOWN"nstreet1" : (["x-coord" : 9, "y-coord" : 7, "symbol" : " | ", "color" : "%^BOLD%^%^WHITE%^"]),
   MAINTOWN"square" : (["x-coord" : 9, "y-coord" : 8, "symbol" : " @ ", "color" : "%^BOLD%^%^YELLOW%^"]),
   MAINTOWN"sstreet1" : (["x-coord" : 9, "y-coord" : 9, "symbol" : " | ", "color": "%^BOLD%^%^WHITE%^"]),
   MAINTOWN"sstreet2" : (["x-coord" : 9, "y-coord" : 10, "symbol" : " | ", "color": "%^BOLD%^%^WHITE%^"]),
   MAINTOWN"sstreet3" : (["x-coord" : 9, "y-coord" : 11, "symbol" : " # ", "color" : "%^BOLD%^%^YELLOW%^"]),
   MAINTOWN"mtower1" : (["x-coord" : 6, "y-coord" : 7, "symbol" : " M ", "color" : "%^BOLD%^%^CYAN%^"]),
   MAINTOWN"wstreet3" : (["x-coord" : 6, "y-coord" : 8, "symbol" : " # ", "color" : "%^BOLD%^%^YELLOW%^"]),
   MAINTOWN"library" : (["x-coord" : 6, "y-coord" : 9, "symbol" : " L ", "color" : "%^BOLD%^%^CYAN%^"]),
   MAINTOWN"weapon" : (["x-coord" : 7, "y-coord" : 7, "symbol" : " W ", "color" : "%^BOLD%^%^CYAN%^"]),
   MAINTOWN"wstreet2" : (["x-coord" : 7, "y-coord" : 8, "symbol" : " = ", "color": "%^BOLD%^%^WHITE%^"]),
   MAINTOWN"wbar" : (["x-coord" : 7, "y-coord" : 9, "symbol" : " B ", "color" : "%^BOLD%^%^CYAN%^"]),
   MAINTOWN"clothing" : (["x-coord" : 8, "y-coord" : 7, "symbol" : " J ", "color" : "%^BOLD%^%^CYAN%^"]),
   MAINTOWN"wstreet1" : (["x-coord" : 8, "y-coord" : 8, "symbol" : " = ", "color": "%^BOLD%^%^WHITE%^"]),
   MAINTOWN"general" : (["x-coord" : 8, "y-coord" : 9, "symbol" : " G ", "color" : "%^BOLD%^%^CYAN%^"]),
   MAINTOWN"instruments" : (["x-coord" : 8, "y-coord" : 5, "symbol" : " i ", "color" : "%^BOLD%^%^CYAN%^"]),
   MAINTOWN"bardcomps" : (["x-coord" : 8, "y-coord" : 6, "symbol" : " I ", "color" : "%^BOLD%^%^CYAN%^"]),
   MAINTOWN"church" : (["x-coord" : 10, "y-coord" : 6, "symbol" : " C ", "color" : "%^BOLD%^%^CYAN%^"]),
   MAINTOWN"bank" : (["x-coord" : 10, "y-coord" : 9, "symbol" : " b ", "color" : "%^BOLD%^%^CYAN%^"]),
   MAINTOWN"estreet1" : (["x-coord" : 10, "y-coord" : 8, "symbol" : " = ", "color": "%^BOLD%^%^WHITE%^"]),
   MAINTOWN"estreet2" : (["x-coord" : 11, "y-coord" : 8, "symbol" : " = ", "color": "%^BOLD%^%^WHITE%^"]),
   MAINTOWN"estreet3" : (["x-coord" : 12, "y-coord" : 8, "symbol" : " # ", "color" : "%^BOLD%^%^YELLOW%^"]),
   MAINTOWN"healer" : (["x-coord" : 10, "y-coord" : 7, "symbol" : " H ", "color" : "%^BOLD%^%^CYAN%^"]),
   MAINTOWN"armor" : (["x-coord" : 11, "y-coord" : 7, "symbol" : " A ", "color" : "%^BOLD%^%^CYAN%^"]),
   MAINTOWN"stable" : (["x-coord" : 11, "y-coord" : 9, "symbol" : " S ", "color" : "%^BOLD%^%^CYAN%^"]),
   MAINTOWN"psifoyer" : (["x-coord" : 12, "y-coord" : 7, "symbol" : " Ps", "color" : "%^BOLD%^%^CYAN%^"]),
   MAINTOWN"scribe" : (["x-coord" : 12, "y-coord" : 9, "symbol" : " Sc", "color" : "%^BOLD%^%^CYAN%^"]),
   FROAD"1" : (["x-coord" : 9, "y-coord" : 4, "symbol" : " * ", "color" : "%^RESET%^%^GREEN%^"]),
   FROAD"2" : (["x-coord" : 9, "y-coord" : 3, "symbol" : " * ", "color" : "%^RESET%^%^GREEN%^"]),
   FROAD"3" : (["x-coord" : 10, "y-coord" : 2, "symbol" : " * ", "color" : "%^RESET%^%^GREEN%^"]),
   FROAD"4" : (["x-coord" : 13, "y-coord" : 8, "symbol" : " * ", "color" : "%^RESET%^%^GREEN%^"]),
   FROAD"5" : (["x-coord" : 14, "y-coord" : 8, "symbol" : " * ", "color" : "%^RESET%^%^GREEN%^"]),
   FROAD"6" : (["x-coord" : 15, "y-coord" : 8, "symbol" : " * ", "color" : "%^RESET%^%^GREEN%^"]),
   FROAD"7" : (["x-coord" : 16, "y-coord" : 8, "symbol" : " * ", "color" : "%^RESET%^%^GREEN%^"]),
   FROAD"8" : (["x-coord" : 5, "y-coord" : 8, "symbol" : " * ", "color" : "%^RESET%^%^GREEN%^"]),
   FROAD"9" : (["x-coord" : 4, "y-coord" : 8, "symbol" : " * ", "color" : "%^RESET%^%^GREEN%^"]),
   FROAD"10" : (["x-coord" : 3, "y-coord" : 8, "symbol" : " * ", "color" : "%^RESET%^%^GREEN%^"]),
   FROAD"11" : (["x-coord" : 2, "y-coord" : 8, "symbol" : " * ", "color" : "%^RESET%^%^GREEN%^"]),
   FROAD"12" : (["x-coord" : 9, "y-coord" : 12, "symbol" : " * ", "color" : "%^RESET%^%^GREEN%^"]),
   FROAD"13" : (["x-coord" : 9, "y-coord" : 13, "symbol" : " * ", "color" : "%^RESET%^%^GREEN%^"]),
   FROAD"14" : (["x-coord" : 9, "y-coord" : 14, "symbol" : " * ", "color" : "%^RESET%^%^GREEN%^"]),
   FROAD"15" : (["x-coord" : 8, "y-coord" : 15, "symbol" : " * ", "color" : "%^RESET%^%^GREEN%^"]),
   FROAD"16" : (["x-coord" : 7, "y-coord" : 16, "symbol" : " * ", "color" : "%^RESET%^%^GREEN%^"]),
   FROAD"17" : (["x-coord" : 6, "y-coord" : 17, "symbol" : " Ho", "color" : "%^BOLD%^%^BLACK%^"]),
   FROAD"18" : (["x-coord" : 10, "y-coord" : 15, "symbol" : " * ", "color" : "%^RESET%^%^GREEN%^"]),
   FROAD"19" : (["x-coord" : 11, "y-coord" : 16, "symbol" : " * ", "color" : "%^RESET%^%^GREEN%^"]),
   FROAD"20" : (["x-coord" : 12, "y-coord" : 17, "symbol" : " * ", "color" : "%^RESET%^%^GREEN%^"]),
   HILL"mine1" : (["x-coord" : 12, "y-coord" : 18, "symbol" : " Mi", "color" : "%^BOLD%^%^BLACK%^"]),
   KEEP"path4" : (["x-coord" : 1, "y-coord" : 7, "symbol" : " K ", "color" : "%^BOLD%^%^BLUE%^"]),
   GRAVEYARD"cemetary1" : (["x-coord" : 16, "y-coord" : 9, "symbol" : " Gy", "color" : "%^BOLD%^%^BLACK%^"]),
   MEADOWR"meadow2" : (["x-coord" : 10, "y-coord" : 1, "symbol" : " Me", "color" : "%^BOLD%^%^YELLOW%^"]),]);
}

void build_grid(int x, int y)
{
    int z, b, len;
    string *myRooms, sym, which, tRoom;
    MY_GRID = ([]);
    myRooms = keys(MAP_GRID);
    for(z = 0;z < sizeof(myRooms);z++)
    {
        tRoom = myRooms[z];
        which = MAP_GRID[tRoom]["x-coord"] + "-" + MAP_GRID[tRoom]["y-coord"];
        //tell_object(ETO, "tRoom = "+tRoom + " which = "+which);
        MY_GRID += ([ which : (["file" : myRooms[z], "symbol" : MAP_GRID[myRooms[z]]["symbol"], "color" : MAP_GRID[myRooms[z]]["color"]]), ]);
        continue;
    }
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
}

int read_func(string str)
{
    string *tmp, tmp2, which, loc;
    int x, y;
    if(!str) return notify_fail("Read what?\n");
    if(str != "map") return 0;
    if(!objectp(TP)) return 0;
    if(!mapp(MY_GRID)) build_grid(20,20);
    tell_object(TP, "\n%^BOLD%^%^GREEN%^       N\n\n   W - | - E\n\n       S%^RESET%^\n");
    tmp = ({});
    //tell_object(ETO, identify((MY_GRID)));
    //return 1;
    for(y = 1;y < 20;y++)
    {
        tmp2 = "";
        for(x = 1;x < 20;x++)
        {
            which = x + "-" + y;
            if(objectp(EETO))
            {
                if(base_name(EETO) == MY_GRID[which]["file"] ||
                base_name(EETO) == MY_GRID[which]["file"]+".c")
                {
                    tmp2 += "%^BOLD%^%^GREEN%^"+MY_GRID[which]["symbol"] +"%^RESET%^";
                    loc = "%^BOLD%^%^GREEN%^"+MY_GRID[which]["symbol"] +"%^RESET%^";
                    continue;
                }
            }
            if(MY_GRID[which]["color"] != "NIL") tmp2 += MY_GRID[which]["color"] + MY_GRID[which]["symbol"]+"%^RESET%^";
            else tmp2 += MY_GRID[which]["symbol"]+"%^RESET%^";
            continue;
        }
        tmp += ({tmp2});        
    }
    
    if(stringp(loc)) tmp += ({"\n\n%^BOLD%^%^WHITE%^Map Legend   (Your Location: "+loc+")\n"});
    else tmp += ({"\n\n%^BOLD%^%^WHITE%^Map Legend\n"});
    tmp += ({"%^YELLOW%^@%^WHITE%^: Town square     %^YELLOW%^#%^WHITE%^: Town gates       %^CYAN%^B%^WHITE%^: Tavern"});
    tmp += ({"%^BOLD%^%^CYAN%^b%^WHITE%^: Bank            %^CYAN%^G%^WHITE%^: General store    %^CYAN%^S%^WHITE%^: Stable/tether"});
    tmp += ({"%^BOLD%^%^CYAN%^W%^WHITE%^: Weapons         %^CYAN%^C%^WHITE%^: Church           %^CYAN%^H%^WHITE%^: Healer"});
    tmp += ({"%^BOLD%^%^CYAN%^A%^WHITE%^: Armorer         %^CYAN%^J%^WHITE%^: Clothing         %^CYAN%^M%^WHITE%^: Mage tower"});
    tmp += ({"%^BOLD%^%^CYAN%^L%^WHITE%^: Library         %^CYAN%^Sc%^WHITE%^: Scribe          %^CYAN%^Ps%^WHITE%^: Psion enclave"});
    tmp += ({"%^BOLD%^%^CYAN%^i%^WHITE%^: Instruments     %^CYAN%^I%^WHITE%^: Bard components  %^CYAN%^|%^WHITE%^: North/South Street"});
    tmp += ({"%^BOLD%^%^WHITE%^=: East/West Street"});
    tmp += ({"%^RESET%^%^GREEN%^*%^BOLD%^%^WHITE%^: Forest         %^BOLD%^%^BLACK%^Ho%^WHITE%^: Hole"});
    tmp += ({"%^BOLD%^%^BLACK%^Mi%^WHITE%^: Mine           %^BOLD%^%^BLUE%^K%^WHITE%^: Keep            %^BOLD%^%^BLACK%^Gy%^WHITE%^: Graveyard"});
    tmp += ({"%^BOLD%^%^YELLOW%^Me%^WHITE%^: Meadow%^RESET%^"});
    TP->more(tmp);  
    return 1;
}

mixed map_directory(string dir, int width, int height)
{
    int x;
    string *files;
    files = get_dir(dir);
    if(!sizeof(files)) return;
    if(!intp(width) || !intp(height)) return;
    
    
}


mixed build_room(string file)
{
    string *myExits, *myDests;
    if(!file_exists(file) && !file_exists(file+".c")) return;
    
    
}

