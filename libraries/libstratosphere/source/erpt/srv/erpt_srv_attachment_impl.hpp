/*
 * Copyright (c) 2018-2020 Atmosphère-NX
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once
#include <stratosphere.hpp>

namespace ams::erpt::srv {

    class Attachment;

    class AttachmentImpl {
        private:
            Attachment *attachment;
        public:
            AttachmentImpl();
            ~AttachmentImpl();
        public:
            Result Open(const AttachmentId &attachment_id);
            Result Read(ams::sf::Out<u32> out_count, const ams::sf::OutBuffer &out_buffer);
            Result SetFlags(AttachmentFlagSet flags);
            Result GetFlags(ams::sf::Out<AttachmentFlagSet> out);
            Result Close();
            Result GetSize(ams::sf::Out<s64> out);
    };
    static_assert(erpt::sf::IsIAttachment<AttachmentImpl>);

}
