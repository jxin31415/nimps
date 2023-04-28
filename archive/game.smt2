(set-logic LIA)

( synth-inv inv-f ( ( a Int )( iter Int )( sum Int )( win Int )( a_0 Int )( iter_0 Int )( iter_1 Int )( iter_2 Int )( sum_0 Int )( sum_1 Int )( sum_2 Int )( sum_3 Int )( win_0 Int )( win_1 Int )( win_2 Int )( win_3 Int ) ))

( define-fun pre-f ( ( a Int )( iter Int )( sum Int )( win Int )( a_0 Int )( iter_0 Int )( iter_1 Int )( iter_2 Int )( sum_0 Int )( sum_1 Int )( sum_2 Int )( sum_3 Int )( win_0 Int )( win_1 Int )( win_2 Int )( win_3 Int ) ) Bool
        ( and
                ( = a a_0 )
                ( = iter iter_0 )
                ( = sum sum_0 )
                ( = win win_0 )
                ( = sum_0 0 )
                ( = win_0 0 )
                ( = iter_0 0 )
                ( >= a_0 1)
                ( <= a_0 3)
        )
)

( define-fun trans-f ( ( a Int )( iter Int )( sum Int )( win Int )( a_0 Int )( iter_0 Int )( iter_1 Int )( iter_2 Int )( sum_0 Int )( sum_1 Int )( sum_2 Int )( sum_3 Int )( win_0 Int )( win_1 Int )( win_2 Int )( win_3 Int )( a! Int )( iter! Int )( sum! Int )( win! Int )( a_0! Int )( iter_0! Int )( iter_1! Int )( iter_2! Int )( sum_0! Int )( sum_1! Int )( sum_2! Int )( sum_3! Int )( win_0! Int )( win_1! Int )( win_2! Int )( win_3! Int ) ) Bool
        ( or
                ( and
                        ( = iter_1 iter )
                        ( = sum_1 sum )
                        ( = win_1 win )
                        ( = iter_1 iter! )
                        ( = sum_1 sum! )
                        ( = win_1 win! )
                        ( = a a! )
                        ( = iter iter! )
                        ( = win win! )
                )
                ( and
                        ( = iter_1 iter )
                        ( = sum_1 sum )
                        ( = win_1 win )
                        ( < sum_1 21 )
                        ( = sum_2 ( + sum_1 a_0 ) )
                        ( >= sum_2 21 )
                        ( = win_2 1 )
                        ( = win_3 win_2 )
                        ( = sum_3 ( + sum_2 ( - 4 a_0 ) ) )
                        ( = iter_2 ( + iter_1 1 ) )
                        ( = iter_2 iter! )
                        ( = sum_3 sum! )
                        ( = win_3 win! )
                        (= a a_0 )
                        (= a! a_0 )
                )
                ( and
                        ( = iter_1 iter )
                        ( = sum_1 sum )
                        ( = win_1 win )
                        ( < sum_1 21 )
                        ( = sum_2 ( + sum_1 a_0 ) )
                        ( not ( >= sum_2 21 ) )
                        ( = win_3 win_1 )
                        ( = sum_3 ( + sum_2 ( - 4 a_0 ) ) )
                        ( = iter_2 ( + iter_1 1 ) )
                        ( = iter_2 iter! )
                        ( = sum_3 sum! )
                        ( = win_3 win! )
                        (= a a_0 )
                        (= a! a_0 )
                )
        )
)

( define-fun post-f ( ( a Int )( iter Int )( sum Int )( win Int )( a_0 Int )( iter_0 Int )( iter_1 Int )( iter_2 Int )( sum_0 Int )( sum_1 Int )( sum_2 Int )( sum_3 Int )( win_0 Int )( win_1 Int )( win_2 Int )( win_3 Int ) ) Bool
        ( or
                ( not
                        ( and
                                ( = a a_0)
                                ( = iter iter_1)
                                ( = sum sum_1)
                                ( = win win_1)
                        )
                )
                ( not
                        ( and
                                ( not ( < sum_1 21 ) )
                                ( not ( > win_1 0 ) )
                        )
                )
        )
)

(inv-constraint inv-f pre-f trans-f post-f)

(check-synth)