#include<stdio.h>
int pit_choice_player (int *, int);
void display (int *, int);
int player_2 (int *, int);
int count_check_p1 (int *, int);
int count_check_p2 (int *, int);
int
main ()
{
  int a[8] = { 3, 3, 3, 3, 3, 3, 3, 3 };
  int storeA = 0, storeB = 0, house1 = 0, house2 = 0;
  int pit_len = 8, temp = 0, i = 4, j = 4, p1 = 1, p2 = 2;
  printf ("\n display\n");
  display (a, pit_len);
  while (1)
    {
      if (count_check_p1 (a, j))
	{
	  break;
	}
      temp = pit_choice_player (a, p1);
      house1 = player_2 (a, temp);
      storeA = storeA + house1;
      printf ("player 1 store collection=%d", storeA);
      display (a, pit_len);
      if (count_check_p2 (a, j))
	{
	  break;
	}
      temp = pit_choice_player (a, p2);
      house2 = player_2 (a, temp);
      storeB = storeB + house2;
      printf ("player 2 store collection=%d", storeB);
      display (a, pit_len);
    }
  if (storeA == storeB)
    {
      printf ("It's a tie");
    }
  else
    {
      storeA > storeB ? printf ("player 1 won") : printf ("player 2 won");
    }
}
int  count_check_p1 (int *a, int max)
{
  int i;
  for (i = 0; i < max; i++)
    {
      if (a[i] == 0)
	continue;
      else
	return 0;
    }
  return 1;
}
int  count_check_p2 (int *a, int max)
{
  int i;
  for (i = max; i < 8; i++)
    {
      if (a[i] == 0)
	continue;
      else
	return 0;
    }
  return 1;
}
int  pit_choice_player (int *a, int player)
{
  int i = 0;
  if (player == 1)
    {
    label:
      printf ("\nPlayer 1 select pits from 0 to 3::");
      fflush (stdin);
      scanf ("%d", &i);
      if (i >= 0 && i < 4)
	{
	  if (a[i])
	    return i;
	  else
	    goto label;
	}
      else
	{
	  printf ("\n Enter valid pits numbers\n");
	  goto label;
	}
    }
  else
    {
    label1:
      printf ("\n Player 2 select pits from 4 to 7::");
      fflush (stdin);
      scanf ("%d", &i);
      if (i >= 4 && i < 8)
	{
	  if (a[i])
	    return i;
	  else
	    goto label1;
	}
      else
	{
	  printf ("\nEnter valid pits numbers");
	  goto label1;
	}
    }
}

void
display (int *a, int pit_len)
{
  int k = 0;
  printf ("\n   player2\n");
  for (k = pit_len - 1; k > 3; k--)
    {
      printf ("%d ", a[k]);
    }
  printf ("\n\n\n");
  for (k = 0; k < 4; k++)
    {
      printf ("%d ", a[k]);
    }
  printf ("\n  player1\n");
}

int  player_2 (int *a, int pitno)
{
  int temp = 0, store2 = 0, i = 0;
  temp = a[pitno];
  a[pitno] = 0;
  if (pitno == 7)
    {
      pitno = -1;
    }
  for (i = pitno + 1; (temp >= 0) && (i < 8); i++)
    {
      if (i != 7)
	{
	  if (((a[i] != 0) || (a[i] == 0)) && (temp != 0))
	    {

	      a[i]++;
	      temp--;
	    }
	  else if ((a[i] != 0) && (temp == 0))
	    {

	      temp = a[i];
	      a[i] = 0;
	    }
	  else if (a[i] == 0 && temp == 0)
	    {
	      if (a[i + 1] != 0)
		{
		  store2 = a[i + 1];
		  a[i + 1] = 0;
		  return store2;
		}
	      else
		{
		  printf ("player 1  chance");
		  return 0;
		}
	    }
	  else if ((a[i] == 0) && (a[i + 1] == 0))
	    {
	      return 0;
	    }
	  else
	    {
	      printf ("\nPlayer 2......");
	    }
	}
      else
	{
	  if ((i == 7) && (temp == 0))
	    {
	      if (a[i] == 0)
		{
		  if (a[0] != 0)
		    {
		      store2 = a[0];
		      a[0] = 0;
		      return store2;
		    }
		  else
		    {
		      printf ("player 1 turn");
		      return 0;
		    }
		}
	      else
		{
		  temp = a[i];
		  a[i] = 0;
		  i = -1;
		}
	    }
	  else if ((i == 7) && (temp != 0))
	    {
	      a[i] = a[i] + 1;
	      temp--;
	      i = -1;
	    }
	  else
	    {
	      a[i] = a[i] + 1;
	      temp--;
	    }
	}
    }
  return 0;
}
