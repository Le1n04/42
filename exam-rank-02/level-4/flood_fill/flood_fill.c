  typedef struct  s_point
  {
    int           x;
    int           y;
  }               t_point;

void filler(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.x < 0 || cur.y < 0 || cur.x >= size.x || cur.y > size.y || tab[cur.y][cur.x])
		return;
	tab[cur.y][cur.x] = 'F';
	filler(tab, size, (t_point){cur.x -1, cur.y}, to_fill);
	filler(tab, size, (t_point){cur.x +1, cur.y}, to_fill);
	filler(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	filler(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
	filler(tab, size, begin, tab[begin.y][begin.x]);
}