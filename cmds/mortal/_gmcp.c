/*
  _gmcp.c
  
  Player command to enable/disable or check status of GMCP.
  
  -- Tlaloc -- 9.16.21
*/

int cmd_gmcp(string str)
{
    string res;
    int gmcp_enabled = has_gmcp(this_player());
    
    printf("GMCP Status: %d\n", gmcp_enabled);
    
    if(gmcp_enabled)
    {
        mapping char_info = ([
                              "hp"    : this_player()->query_hp() + "",
                              "maxhp" : this_player()->query_max_hp() + "",
                            ]);
                            
        res = "Char.Vitals " + json_encode(char_info) + "\n";
        
        printf("<GMCP sending : %s\n", res);
        this_player()->send_gmcp(res);
    }
    
    return 1;
}                             