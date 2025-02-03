/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:36:59 by hramaros          #+#    #+#             */
/*   Updated: 2025/02/03 12:37:53 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

// Événements
# define ON_KEYPRESS 2
# define ON_KEYRELEASE 3
# define ON_MOUSEDOWN 4
# define ON_MOUSEUP 5
# define ON_MOUSEMOVE 6
# define ON_EXPOSE 12
# define ON_DESTROY 17

// Masques d'événements
# define NO_EVENT_MASK 0L
# define KEY_PRESS_MASK (1L << 0)
# define KEY_RELEASE_MASK (1L << 1)
# define BUTTON_PRESS_MASK (1L << 2)
# define BUTTON_RELEASE_MASK (1L << 3)
# define ENTER_WINDOW_MASK (1L << 4)
# define LEAVE_WINDOW_MASK (1L << 5)
# define POINTER_MOTION_MASK (1L << 6)
# define POINTER_MOTION_HINT_MASK (1L << 7)
# define BUTTON1_MOTION_MASK (1L << 8)
# define BUTTON2_MOTION_MASK (1L << 9)
# define BUTTON3_MOTION_MASK (1L << 10)
# define BUTTON4_MOTION_MASK (1L << 11)
# define BUTTON5_MOTION_MASK (1L << 12)
# define BUTTON_MOTION_MASK (1L << 13)
# define KEYMAP_STATE_MASK (1L << 14)
# define EXPOSURE_MASK (1L << 15)
# define VISIBILITY_CHANGE_MASK (1L << 16)
# define STRUCTURE_NOTIFY_MASK (1L << 17)
# define RESIZE_REDIRECT_MASK (1L << 18)
# define SUBSTRUCTURE_NOTIFY_MASK (1L << 19)
# define SUBSTRUCTURE_REDIRECT_MASK (1L << 20)
# define FOCUS_CHANGE_MASK (1L << 21)
# define PROPERTY_CHANGE_MASK (1L << 22)
# define COLORMAP_CHANGE_MASK (1L << 23)
# define OWNER_GRAB_BUTTON_MASK (1L << 24)

#endif // MLX_EVENTS_H
