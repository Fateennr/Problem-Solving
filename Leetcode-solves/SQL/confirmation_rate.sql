-- delimiter //

-- Create function rateCalculate(
--     confirmed_count decimal(10,2),
--     request_count decimal(10,2)
-- )
-- returns decimal(10,2)
-- deterministic
-- begin
--     return confirmed_count / request_count;
-- end; //

-- delimiter;


-- SELECT calculate_discount(100.00, 0.15);

-- select c.user_id, ( confirmation_count / count(*) ) as confirmation_rate
-- from Confirmations c
-- left join 
-- (
--     select user_id, count(*) as confirmation_count from
--     Confirmations
--     where action = "confirmed"
--     group by user_id
-- ) d
-- on c.user_id = d.user_id
-- group by user_id;


-- select user_id, ( confirmation_count / count(*) ) as confirmation_rate
-- from
-- ( 
    
select s.user_id, 
(
    round(
    sum(
        case 
            when c.action = "confirmed" 
            then 1 
            else 0
        end
    ) * 1.0 / count(s.user_id) 
    , 2)
) as confirmation_rate
from Confirmations c
right join Signups s
on
c.user_id = s.user_id
group by s.user_id
;

-- ) t
-- left join 
-- (
--     select user_id, count(*) as confirmation_count from
--     Confirmations
--     where action = "confirmed"
--     group by user_id
-- ) w
-- on t.user_id = w.user_id;
