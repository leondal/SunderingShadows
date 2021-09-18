/**
 * @file
 */

/**
 * Rolls a NdM dice
 *
 * @param num N
 * @param sides M
 * @reutn Sum of the roll
 */
 
//Tlaloc added advantage/disadvantage modifier 9.18.21
 
int roll_dice(int num, int sides, int adv)
{
    int x, cnt, cnt2;

    cnt = 0;
    cnt2 = 0;
        
    for (x = 0; x < num; x++)
        cnt += random(sides) + 1;
    
    if(adv != 0)
    {
        for(x = 0; x < num; x++)
            cnt2 += random(sides) + 1;
        
        if(adv < 0)
            cnt = min( ({ cnt, cnt2 }) );
        else
            cnt = max( ({ cnt, cnt2 }) );
    }     
        
    return cnt;
}
