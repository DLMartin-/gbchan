#ifndef CPU_INC_CPU_CPU_H_
#define CPU_INC_CPU_CPU_H_
#include <cstdint>
#include <cstddef>

namespace gb {
  class cpu {
    enum struct stack_pointer : std::uint16_t {};
    enum struct program_counter : std::uint16_t {};
    enum struct opcode : std::uint8_t {};
    static constexpr opcode CbPrefix {0xcb};
    using instruction = std::uint16_t(*)(cpu*) noexcept;

    public:
      cpu(std::byte* mmu) noexcept;

      std::uint16_t run_cycle() noexcept;
    private:
      std::byte read_mmu() noexcept;
      opcode fetch() noexcept;
      instruction decode(opcode opcode) noexcept;
      instruction decode_cb(opcode opcode) noexcept;
      std::uint16_t execute(instruction instruction) noexcept;
      
      std::byte* mmu_ {nullptr};
      stack_pointer sp_ {0};
      program_counter pc_ {0};
      std::uint16_t cycles_run_ {0};
  };
}

#endif

