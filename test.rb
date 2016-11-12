require 'ffi'

module Library
  extend FFI::Library
  ffi_lib 'test.dll'

  attach_function :FakeRecProcessPages, [:int, :string, :pointer], :int

  def self.process_pages(id, file, image_files)
    FFI::MemoryPointer.new(:pointer, image_files.length + 1) do |p|
      p.write_array_of_pointer image_files.map(&FFI::MemoryPointer.method(:from_string)) << nil
      return FakeRecProcessPages id, file, p
    end

  end
end
