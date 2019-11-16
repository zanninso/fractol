/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 23:03:23 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/11/16 01:52:25 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H

# define DEFINE_H
// # define MENU_COLOR (t_argb){0, 164, 164, 164}
# define MENU_COLOR 0x525252
# define RED (t_argb){0, 255, 0, 0}
# define GREEN (t_argb){0, 0, 255, 0}
# define BLUE (t_argb){0, 0, 0, 255}
# define GET_RGB(v) (t_argb){0, v >> 16 & 255, v >> 8 & 255, v & 255}
# define START_Y_MENU 30
# define START_X_MENU 20
# define Y_STEP 10
# define Y_COLOR_TITLE START_Y_MENU
# define Y_COLOR_SELECTOR Y_COLOR_TITLE + Y_STEP
# define Y_COLORS Y_COLOR_SELECTOR + Y_STEP
# define COLORS_WIDTH 50
# define COLORS_HEIGHT 20
# define Y_COLOR_SLIDE Y_COLOR_SELECTOR + Y_STEP + COLORS_WIDTH
# define COLOR_SLIDE_HEIGHT 10

#endif