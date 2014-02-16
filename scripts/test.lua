-- test.lua
print("Hello World")

function fact (n)
   if 0 == n then
      return 1
   else
      return n * fact(n - 1)
   end
end

print("fact(10) = " .. fact(10))

-- math
print("math.sin(3) = " .. math.sin(3))

-- test export `c_add(a, b)' function
print("c_add(2, 3) = " .. c_add(2, 3))
