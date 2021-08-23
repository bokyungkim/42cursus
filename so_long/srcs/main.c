#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../mlx/mlx.h"

#define X_EVENT_KEY_PRESS	2
#define X_EVENT_KEY_RELEASE	3
#define X_EVENT_KEY_EXIT	17

#define KEY_ESC	53
#define KEY_Q	12

int	tree;

typedef struct s_img
{
	void	*img;
	int		*data;

	int		size_l;
	int		bpp;
	int		endian;
}	t_img;

typedef struct	s_game
{
	void	*mlx;
	void	*win;
	t_img	img1;
	t_img	img2;
}	t_game;

void	window_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 500, 500, "bokim");
}

void	img_init(t_game *game, char *file_name, int img_num)
{
	int img_width;
	int img_height;

	if (img_num == 1)
	{
		game->img1.img = mlx_xpm_file_to_image(game->mlx, file_name, &img_width, &img_height);
		game->img2.img = mlx_xpm_file_to_image(game->mlx, "../textures/tree.XPM", &img_width, &img_height);
	}
	else if (img_num == 2)
		game->img2.img = mlx_xpm_file_to_image(game->mlx, file_name, &img_width, &img_height);

	// mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}

int	deal_key(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == KEY_Q && tree == 0)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img2.img, 0, 0);
		tree = 1;
	}
	else if (keycode == KEY_Q && tree == 1)
	{
		printf("in the destroy loop\n");
		// 그림을 없애고 싶으면 그냥 검정색으로 덮어주기
		// mlx_destroy_image(game->mlx, game->img2.img);
		// img_init(game, "../textures/tree.XPM", 2);
		tree = 0;
	}
	return (0);
}

int main_loop(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img1.img, 0, 0);
	mlx_hook(game->win, X_EVENT_KEY_PRESS, 0, &deal_key, game);
	return (0);
}

int	main(void)
{
	t_game	game;
	tree = 0;

	window_init(&game);
	img_init(&game, "../textures/wall_n.xpm", 1);
	// mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &deal_key, &game);
	
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(&game.mlx);
}
