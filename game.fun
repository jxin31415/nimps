game = fun {
    sum = 0
    iter = 0

    while sum < 21 [] {
        b = ??

        sum = sum + a

        assert sum >= 21 || sum + b < 21
        
        sum = sum + b
        iter = iter + 1
    }
}
