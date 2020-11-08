#include "cpu.h"

#include <functional>

namespace gb {

  std::uint16_t cpu::run_cycle() noexcept {
    auto opcode = fetch();
    instruction instruction {nullptr};
    if(opcode == cpu::CbPrefix) {
      opcode = fetch();
      instruction = decode_cb(opcode);
    }
    else {
      instruction = decode(opcode);
    }

    return execute(instruction);
  }

  cpu::opcode cpu::fetch() noexcept {
    return static_cast<cpu::opcode>(read_mmu());
  }

  std::byte cpu::read_mmu() noexcept {
    auto idx = static_cast<std::uint16_t>(pc_);
    pc_ = static_cast<cpu::program_counter>(static_cast<std::uint16_t>(pc_) + 1);
    return mmu_[idx];
  }

  cpu::instruction cpu::decode(cpu::opcode opcode) noexcept {
    cpu::instruction instruction_set[] = {
      [](cpu* cpu) noexcept -> std::uint16_t { return 0; },
      [](cpu* cpu) noexcept -> std::uint16_t { return 1; },
      //To-do: Flesh out remaining 256 instructions
    };

    auto const idx = static_cast<uint8_t>(opcode);
    return instruction_set[idx];
  }

  cpu::instruction cpu::decode_cb(cpu::opcode opcode) noexcept {
    cpu::instruction instruction_set[] = {
      [](cpu* cpu) noexcept -> std::uint16_t { return 0; },
      [](cpu* cpu) noexcept -> std::uint16_t { return 1; },
      //To-do: Flesh out remaining 256 cb-prefixed instructions
    };

    auto const idx = static_cast<uint8_t>(opcode);
    return instruction_set[idx];
  }

  std::uint16_t cpu::execute(cpu::instruction instruction) noexcept {
    return std::invoke(instruction, this);
  }
}
