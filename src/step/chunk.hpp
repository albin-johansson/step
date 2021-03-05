#ifndef STEP_CHUNK_HEADER
#define STEP_CHUNK_HEADER

#include "data.hpp"
#include "step_api.hpp"
#include "types.hpp"

namespace step {

/**
 * \class chunk
 *
 * \brief Represents "chunks", that store the tile layer data for
 * infinite maps.
 *
 * \since 0.1.0
 *
 * \headerfile step_chunk.hpp
 */
class chunk final
{
 public:
  explicit chunk(const json& json)
      : m_x{json.at("x").get<int>()}
      , m_y{json.at("y").get<int>()}
      , m_width{json.at("width").get<int>()}
      , m_height{json.at("height").get<int>()}
      , m_data{json.at("data")}
  {}

  /**
   * \brief Returns the x-coordinate of the chunk.
   *
   * \return the x-coordinate of the chunk.
   *
   * \since 0.1.0
   */
  [[nodiscard]] auto x() const noexcept -> int
  {
    return m_x;
  }

  /**
   * \brief Returns the y-coordinate of the chunk.
   *
   * \return the y-coordinate of the chunk.
   *
   * \since 0.1.0
   */
  [[nodiscard]] auto y() const noexcept -> int
  {
    return m_y;
  }

  /**
   * \brief Returns the width of the chunk.
   *
   * \return the width of the chunk.
   *
   * \since 0.1.0
   */
  [[nodiscard]] auto width() const noexcept -> int
  {
    return m_width;
  }

  /**
   * \brief Returns the height of the chunk.
   *
   * \return the height of the chunk.
   *
   * \since 0.1.0
   */
  [[nodiscard]] auto height() const noexcept -> int
  {
    return m_height;
  }

  /**
   * \brief Returns the data associated with the chunk.
   *
   * \return the data associated with the chunk.
   *
   * \since 0.1.0
   */
  [[nodiscard]] auto data() const noexcept -> const detail::data&
  {
    return m_data;
  }

 private:
  int m_x;
  int m_y;
  int m_width;
  int m_height;
  detail::data m_data;
};

}  // namespace step

#endif  // STEP_CHUNK_HEADER
