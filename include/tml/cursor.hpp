#pragma once

#include "utils.hpp"
namespace tml
{

namespace cursor
{

/**
 * @brief Moves the cursor to the top-left corner.
 */
void move_home();

/**
 * @brief Moves the cursor to the specified column and row.
 * 
 * @param col The column to move the cursor to.
 * @param row The row to move the cursor to.
 */
void move_to(int col, int row);

/**
 * @brief Moves the cursor to the specified column while keeping the current row.
 * 
 * @param col The column to move the cursor to.
 */
void move_to_col(int col);

/**
 * @brief Moves the cursor to the specified row while keeping the current column.
 * 
 * @param row The row to move the cursor to.
 */
void move_to_row(int row);

/**
 * @brief Moves the cursor by the specified number of columns and rows relative to its current position.
 * 
 * @param col The number of columns to move the cursor by (positive for right, negative for left).
 * @param row The number of rows to move the cursor by (positive for down, negative for up).
 */
void move_by(int col, int row);

/**
 * @brief Gets the current position of the cursor.
 * 
 * @return A Vector2 object representing the current position of the cursor (column and row).
 */
Vector2 get_pos();

/**
 * @brief Saves the current position of the cursor for later restoration.
 * Use only when you are sure your saved position won't get overwrited by another call to this function.
 */
void save_pos();

/**
 * @brief Restores the cursor to the last saved position.
 */
void restore_pos();

/**
 * @brief Makes the cursor visible.
 */
void show();

/**
 * @brief Hides the cursor.
 */
void hide();

/**
 * @brief Checks if the cursor is currently visible.
 * 
 * @return true if the cursor is visible, false otherwise.
 */
bool is_visible();

}}