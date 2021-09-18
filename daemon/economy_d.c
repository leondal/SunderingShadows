//NOT ACTIVELY USED

// economy_d.c  <<--== Writen by Fire Dragon ==-->>


#define MONEY_TYPES ({ "copper", "silver", "electrum", "gold", "platinum" })


void create() 
{
}

int currency_rate(string type)
{
  switch( type )
    {
      case "copper"   : return 1;
                        break;
      case "silver"   : return 10;
                        break;
      case "electrum" : return 50;
                        break;
      case "gold"     : return 100;
                        break;
      case "platinum" : return 500;
                        break;
    }
  return 0;
}

