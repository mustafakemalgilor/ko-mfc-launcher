/**
 * ______________________________________________________
 * This file is part of ko-ascension-launcher project.
 * 
 * @author       Mustafa Kemal Gılor <mustafagilor@gmail.com> (2015)
 * .
 * SPDX-License-Identifier:	MIT
 * ______________________________________________________
 */

#pragma once

#include "ByteBuffer.hpp"

class Packet : public ByteBuffer
{
public:
	INLINE Packet() : ByteBuffer(), m_opcode(0) { }
	INLINE Packet(uint8 opcode) : ByteBuffer(4096), m_opcode(opcode) {}
	INLINE Packet(uint8 opcode, size_t res) : ByteBuffer(res), m_opcode(opcode) {}
	INLINE Packet(const Packet &packet) : ByteBuffer(packet), m_opcode(packet.m_opcode) {}
	INLINE Packet(uint8 opcode, uint8 subOpcode) : m_opcode(opcode)
	{
		append(&subOpcode, 1);
	}

	INLINE Packet(char* buf, size_t len) : m_opcode(buf[0])
	{
		append(&buf[1], len - 1);
	}

	//! Clear packet and set opcode all in one mighty blow
	INLINE void Initialize(uint8 opcode)
	{
		clear();
		m_opcode = opcode;
	}

	INLINE void FillBytes(uint8 count, uint8 val = 0x00)
	{
		for (int i = 0; i < count; i++)
			append(val);
	}

	INLINE uint8 GetOpcode() const { return m_opcode; }
	INLINE void SetOpcode(uint8 opcode) { m_opcode = opcode; }

protected:
	uint8 m_opcode;
};
