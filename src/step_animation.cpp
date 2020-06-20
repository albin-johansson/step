/**
 * MIT License
 *
 * Copyright (c) 2020 Albin Johansson
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef STEP_ANIMATION_SOURCE
#define STEP_ANIMATION_SOURCE

#include "step_animation.h"

#include "step_frame.h"
#include "step_utils.h"

namespace step {

STEP_DEF
Animation::Animation(const JSON& json)
    : m_frames{detail::fill<std::vector<Frame>>(json)}
{}

STEP_DEF
const std::vector<Frame>& Animation::frames() const
{
  return m_frames;
}

STEP_DEF
int Animation::length() const noexcept
{
  return static_cast<int>(m_frames.size());
}

}  // namespace step

#endif  // STEP_ANIMATION_SOURCE
