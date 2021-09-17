/*
  _gmcp.c
  
  Player command to send send gmcp info from game.
  
  -- Tlaloc -- 9.16.21
*/

#include <std.h>
#include <daemons.h>
#include <new_exp_table.h>

int cmd_gmcp(string str)
{
    string res;
    int gmcp_enabled = has_gmcp(this_player());
    
    printf("GMCP Status: %d\n", gmcp_enabled);
    
    if(gmcp_enabled)
    {
        mapping char_info = ([
                              "hp"        : this_player()->query_hp() + "",
                              "maxhp"     : this_player()->query_max_hp() + "",
                              "encumb"    : this_player()->query_internal_encumbrance() + "",
                              "maxencumb" : this_player()->query_max_internal_encumbrance() + "",
                              "stamina"   : this_player()->query_condition_percent() + "",
                              "pp"        : this_player()->query_mp() + "",
                              "maxpp"     : this_player()->query_max_mp() + "",
                              "xp"        : english_number(this_player()->query_exp()) + "",
                              "grace"     : this_player()->query("available grace") + "",
                              "maxgrace"  : this_player()->query("max grace") + "",
                              "arcana"    : this_player()->query("available arcana") + "",
                              "maxarcana" : this_player()->query("max arcana") + "",
                              
                            ]);
                            
        res = "Char.Vitals " + json_encode(char_info) + "\n";
        
        printf("<GMCP sending : %s\n", res);
        this_player()->send_gmcp(res);
    }
    else
    {
        write("GMCP disabled.\n");
    }
    
    return 1;
}                             